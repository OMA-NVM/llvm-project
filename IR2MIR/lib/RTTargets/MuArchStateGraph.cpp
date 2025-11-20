#include "RTTargets/MuArchStateGraph.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/CodeGen/MachineBasicBlock.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/raw_ostream.h"
#include <cassert>
#include <map>
#include <memory>
#include <set>

namespace llvm {

// Constructor
Node::Node(unsigned NewId, std::unique_ptr<MuArchState> State)
    : Id(NewId), State(std::move(State)) {}

// Copy Constructor
Node::Node(const Node &Node)
    : Id(Node.Id), Successors(Node.Successors), Predecessors(Node.Predecessors),
      State(std::make_unique<MuArchState>(*Node.State)) {}

// Destructor
Node::~Node() {}

// Comparison operator
bool Node::operator<(const Node &Other) const { return Id < Other.Id; }

// Get the ID of the Node
unsigned Node::getId() const { return Id; }

// Get the predecessors of the Node
const std::set<unsigned> Node::getPredecessors() const { return Predecessors; }

// Get the successors of the Node
const std::set<unsigned> Node::getSuccessors() const { return Successors; }

// Add a successor to the Node
void Node::addSuccessor(unsigned SuccessorId) {
  Successors.insert(SuccessorId);
}

// Add a predecessor to the Node
void Node::addPredecessor(unsigned PredecessorId) {
  Predecessors.insert(PredecessorId);
}

// Delete a successor from the Node
bool Node::deleteSuccessor(unsigned SuccessorId) {
  return Successors.erase(SuccessorId) > 0;
}

// Delete a predecessor from the Node
bool Node::deletePredecessor(unsigned PredecessorId) {
  return Predecessors.erase(PredecessorId) > 0;
}

// Check if a given ID is a predecessor of the Node
bool Node::isPredecessor(unsigned PredecessorId) const {
  return Predecessors.find(PredecessorId) != Predecessors.end();
}

// Check if a given ID is a successor of the Node
bool Node::isSuccessor(unsigned SuccessorId) const {
  return Successors.find(SuccessorId) != Successors.end();
}

// Check if the Node is free (no predecessors or successors)
bool Node::isFree() const { return Successors.empty() && Predecessors.empty(); }

// Get a description of the Node
std::string Node::getNodeDescr() const {
  return "ID: " + std::to_string(Id) + ", Name: " + Name.str();
}

// Get the architectural state of the Node
MuArchState &Node::getState() const { return *State; }

MuArchStateGraph::MuArchStateGraph() : Nodes(), NextNodeId(0) {}

MuArchStateGraph::MuArchStateGraph(MuArchStateGraph &G2)
    : Nodes(G2.Nodes), NextNodeId(G2.NextNodeId) {}

MuArchStateGraph::~MuArchStateGraph() {}

unsigned MuArchStateGraph::addNode(MuArchState State, MachineBasicBlock *MBB) {
  unsigned CurrentId = NextNodeId;
  NextNodeId++;
  assert(NextNodeId > 0 &&
         "We used all Node ids for the state graph. Unsigned is not enough!");
  Node Nd(CurrentId, std::make_unique<MuArchState>(State));
  Nd.setName(MBB->getName());
  Nodes.insert(std::make_pair(CurrentId, Nd));
  DEBUG_WITH_TYPE("ilp", dbgs() << "Adding Node with id " << CurrentId << "\n");
  MBBToNodeMap[MBB] = CurrentId;
  return CurrentId;
}

unsigned MuArchStateGraph::addNode(MuArchState State, MachineBasicBlock *MBB,
                                   StringRef NodeName) {
  unsigned CurrentId = NextNodeId;
  NextNodeId++;
  assert(NextNodeId > 0 &&
         "We used all Node ids for the state graph. Unsigned is not enough!");
  Node Nd(CurrentId, std::make_unique<MuArchState>(State));
  Nd.setName(NodeName);
  Nodes.insert(std::make_pair(CurrentId, Nd));
  DEBUG_WITH_TYPE("ilp", dbgs() << "Adding Node with id " << CurrentId << "\n");
  MBBToNodeMap[MBB] = CurrentId;
  return CurrentId;
}

void MuArchStateGraph::addEdge(unsigned FromNode, unsigned ToNode) {
  assert(Nodes.count(FromNode) == 1 && Nodes.count(ToNode) == 1 &&
         "Tried adding an edge between non-existent Nodes.");
  Nodes.at(FromNode).addSuccessor(ToNode);
  Nodes.at(ToNode).addPredecessor(FromNode);
}

void MuArchStateGraph::removeNode(unsigned Node) {
  assert(Nodes.at(Node).isFree() &&
         "Tried to remove a Node which has an edge connected!");
  Nodes.erase(Node);
}

void MuArchStateGraph::removeEdge(unsigned FromNode, unsigned ToNode) {
  Nodes.at(FromNode).deleteSuccessor(ToNode);
  Nodes.at(ToNode).deletePredecessor(FromNode);
}

const std::set<unsigned>
MuArchStateGraph::getPredecessors(unsigned NodeId) const {
  return Nodes.at(NodeId).getPredecessors();
}

const std::set<unsigned>
MuArchStateGraph::getSuccessors(unsigned NodeId) const {
  return Nodes.at(NodeId).getSuccessors();
}

const std::map<unsigned, Node> &MuArchStateGraph::getNodes() const {
  return Nodes;
}

bool MuArchStateGraph::isFree(unsigned Node) const {
  return Nodes.at(Node).isFree();
}

bool MuArchStateGraph::hasEdge(unsigned FromNode, unsigned ToNode) const {
  return Nodes.at(FromNode).isSuccessor(ToNode);
}

void MuArchStateGraph::dump() const {
  for (const auto &Nd : Nodes) {
    errs() << Nd.second.getNodeDescr();
  }
}

bool MuArchStateGraph::dump2Dot(StringRef FileName) {
  std::error_code EC;
  raw_fd_ostream File(FileName, EC, sys::fs::OF_Text);
  if (EC) {
    errs() << "Error opening file: " << EC.message() << "\n";
    return false;
  }

  // Group nodes by function
  std::map<const Function *, std::vector<unsigned>> FunctionToNodes;
  std::vector<unsigned> NodesWithoutFunction; // Nodes without a parent function

  for (const auto &[MBB, NodeId] : MBBToNodeMap) {
    const Function *F = nullptr;

    // Check if BasicBlock is accessible and get parent function
    if (MBB) {
      const BasicBlock *BB = MBB->getBasicBlock();
      if (BB) {
        F = BB->getParent();
      }
    }

    if (F) {
      FunctionToNodes[F].push_back(NodeId);
      outs() << "Mapping MBB " << MBB->getName() << " to Node ID " << NodeId
             << " in Function " << F->getName() << "\n";
    } else {
      NodesWithoutFunction.push_back(NodeId);
      if (!MBB) {
        outs() << "Mapping nullptr MBB to Node ID " << NodeId
               << " (no parent function)\n";
        assert(false && "Should not reach here!");
      }
    }
  }

  // Write the header
  File << "digraph MuArchStateGraph {\n";
  File << "  compound=true;\n"; // Allow edges between clusters

  unsigned ClusterId = 0;

  // Write clusters (subgraphs) for each function
  for (const auto &[MF, NodeIds] : FunctionToNodes) {
    File << "  subgraph cluster_" << ClusterId++ << " {\n";
    File << "    label=\"" << MF->getName().str() << "\";\n";
    File << "    style=filled;\n";
    File << "    color=lightgrey;\n";
    File << "    node [style=filled,color=white];\n";

    // Write nodes in this cluster
    for (unsigned NodeId : NodeIds) {
      const auto &Node = Nodes.at(NodeId);
      File << "    " << Node.getId() << " [label=\"" << Node.getNodeDescr()
           << "\"];\n";
    }

    File << "  }\n";
  }

  // Write nodes without a parent function (outside clusters)
  if (!NodesWithoutFunction.empty()) {
    File << "\n  // Nodes without parent function\n";
    File << "  node [style=filled,color=yellow];\n"; // Different style for
                                                     // orphan nodes

    for (unsigned NodeId : NodesWithoutFunction) {
      const auto &Node = Nodes.at(NodeId);
      File << "  " << Node.getId() << " [label=\"" << Node.getNodeDescr()
           << " (no function)\"];\n";
    }
  }

  // Write edges (after all clusters are defined)
  File << "\n  // Edges\n";
  for (const auto &NodePair : Nodes) {
    const auto &Node = NodePair.second;
    for (unsigned Succ : Node.getSuccessors()) {
      File << "  " << Node.getId() << " -> " << Succ << ";\n";
    }
  }

  // Write the footer
  File << "}\n";
  File.close();
  return true;
}

} // end namespace llvm

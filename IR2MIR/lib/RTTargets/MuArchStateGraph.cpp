#include "RTTargets/MuArchStateGraph.h"
#include "llvm/CodeGen/MachineBasicBlock.h"
#include "llvm/Support/Debug.h"
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
bool Node::operator<(const Node &Other) const {
  return Id < Other.Id;
}

// Get the ID of the Node
unsigned Node::getId() const {
  return Id;
}

// Get the predecessors of the Node
const std::set<unsigned> Node::getPredecessors() const {
  return Predecessors;
}

// Get the successors of the Node
const std::set<unsigned> Node::getSuccessors() const {
  return Successors;
}

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
bool Node::isFree() const {
  return Successors.empty() && Predecessors.empty();
}

// Get a description of the Node
std::string Node::getNodeDescr() const {
  return "Node ID: " + std::to_string(Id);
}

// Get the architectural state of the Node
MuArchState &Node::getState() const {
  return *State;
}



MuArchStateGraph::MuArchStateGraph() : Nodes(), NextNodeId(0) {}

MuArchStateGraph::MuArchStateGraph(MuArchStateGraph &G2)
    : Nodes(G2.Nodes), NextNodeId(G2.NextNodeId) {}

MuArchStateGraph::~MuArchStateGraph() {}

unsigned MuArchStateGraph::addNode(MuArchState State, MachineBasicBlock * MBB) {
  unsigned CurrentId = NextNodeId;
  NextNodeId++;
  assert(NextNodeId > 0 &&
         "We used all Node ids for the state graph. Unsigned is not enough!");
  Node Nd(CurrentId, std::make_unique<MuArchState>(State));
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

const std::set<unsigned> MuArchStateGraph::getPredecessors(unsigned NodeId) const {
  return Nodes.at(NodeId).getPredecessors();
}

const std::set<unsigned> MuArchStateGraph::getSuccessors(unsigned NodeId) const {
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

} // end namespace llvm

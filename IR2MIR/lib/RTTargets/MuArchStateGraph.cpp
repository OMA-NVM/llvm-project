#include "RTTargets/MuArchStateGraph.h"
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



Graph::Graph() : NextNodeId(0), Nodes() {}

Graph::Graph(Graph &G2)
    : NextNodeId(G2.NextNodeId), Nodes(G2.Nodes) {}

Graph::~Graph() {}

unsigned Graph::addNode(std::unique_ptr<MuArchState> State) {
  unsigned CurrentId = NextNodeId;
  NextNodeId++;
  assert(NextNodeId > 0 &&
         "We used all Node ids for the state graph. Unsigned is not enough!");
  Node Nd(CurrentId, std::move(State));
  DEBUG_WITH_TYPE("ilp", dbgs() << "Adding Node with id " << CurrentId << "\n");
  return CurrentId;
}

void Graph::addEdge(unsigned FromNode, unsigned ToNode) {
  assert(Nodes.count(FromNode) == 1 && Nodes.count(ToNode) == 1 &&
         "Tried adding an edge between non-existent Nodes.");
  Nodes.at(FromNode).addSuccessor(ToNode);
  Nodes.at(ToNode).addPredecessor(FromNode);
}

void Graph::removeNode(unsigned Node) {
  assert(Nodes.at(Node).isFree() &&
         "Tried to remove a Node which has an edge connected!");
  Nodes.erase(Node);
}

void Graph::removeEdge(unsigned FromNode, unsigned ToNode) {
  Nodes.at(FromNode).deleteSuccessor(ToNode);
  Nodes.at(ToNode).deletePredecessor(FromNode);
}

const std::set<unsigned> Graph::getPredecessors(unsigned NodeId) const {
  return Nodes.at(NodeId).getPredecessors();
}

const std::set<unsigned> Graph::getSuccessors(unsigned NodeId) const {
  return Nodes.at(NodeId).getSuccessors();
}

const std::map<unsigned, Node> &Graph::getNodes() const {
  return Nodes;
}

bool Graph::isFree(unsigned Node) const {
  return Nodes.at(Node).isFree();
}

bool Graph::hasEdge(unsigned FromNode, unsigned ToNode) const {
  return Nodes.at(FromNode).isSuccessor(ToNode);
}

void Graph::dump() const {
  for (const auto &Nd : Nodes) {
    errs() << Nd.second.getNodeDescr();
  }
}

} // end namespace llvm

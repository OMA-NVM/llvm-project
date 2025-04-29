
#include "RTTargets/MuArchStateGraph.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/raw_ostream.h"
#include <cassert>
#include <map>
#include <memory>
#include <set>

namespace llvm {
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

std::ostream &operator<<(std::ostream &Stream, Graph Graph) {
  for (const auto &Nd : Graph.getNodes()) {
    Stream << Nd.second;
  }
  return Stream;
}

} // end namespace llvm

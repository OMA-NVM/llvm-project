#include "llvm/CodeGen/MachineBasicBlock.h"
#include <cassert>
#include <map>
#include <ostream>
#include <set>

namespace llvm {

  struct MuArchState {
    unsigned UpperBoundCycles;
    unsigned LowerBoundCycles;

    MuArchState(unsigned UpperBound, unsigned LowerBound)
        : UpperBoundCycles(UpperBound), LowerBoundCycles(LowerBound) {}

    unsigned getUpperBoundCycles() const { return UpperBoundCycles; }
    unsigned getLowerBoundCycles() const { return LowerBoundCycles; }

    void setUpperBoundCycles(unsigned Cycles) { UpperBoundCycles = Cycles; }
    void setLowerBoundCycles(unsigned Cycles) { LowerBoundCycles = Cycles; }
  };

class Node {
public:
  explicit Node(unsigned NewId, std::unique_ptr<MuArchState> State);

  Node(const Node &Node);

  ~Node();

  bool operator<(const Node &Node) const;

  unsigned getId() const;

  const std::set<unsigned> getPredecessors() const;

  const std::set<unsigned> getSuccessors() const;

  void addSuccessor(unsigned SuccessorId);

  void addPredecessor(unsigned PrededecessorId);

  bool deleteSuccessor(unsigned SuccessorId);

  bool deletePredecessor(unsigned PrededecessorId);

  bool isPredecessor(unsigned PrededecessorId) const;

  bool isSuccessor(unsigned SuccessorId) const;

  bool isFree() const;

  std::string getNodeDescr() const;

  MuArchState &getState() const;

  friend std::ostream &operator<<(std::ostream &Stream, Node Node) {
    Stream << "Node ID: " << Node.Id;
    return Stream;
  }

  /**
   * Stores the id of this Node.
   */
  unsigned Id;

  /**
   * Stores all ids of succeeding vertices.
   */
  std::set<unsigned> Successors;

  /**
   * Stores all ids of preceding vertices.
   */
  std::set<unsigned> Predecessors;

  /**
   * Stores the architectural state associated with this Node.
   */
  std::unique_ptr<MuArchState> State;
};

class MuArchStateGraph {

public:
  MuArchStateGraph();

  MuArchStateGraph(MuArchStateGraph &G2);

  ~MuArchStateGraph();

  unsigned addNode(MuArchState State, MachineBasicBlock * MBB);

  /**
   * Adds an edge to the graph from the Node with id start to the Node with
   * id end.
   */
  void addEdge(unsigned FromNode, unsigned ToNode);

  void removeNode(unsigned Node);

  /**
   * Removes the edge from the Node with id fromNode to the Node with id
   * toNode from the graph.
   */
  void removeEdge(unsigned FromNode, unsigned ToNode);

  const std::set<unsigned> getPredecessors(unsigned NodeId) const;

  const std::set<unsigned> getSuccessors(unsigned NodeId) const;

  const std::map<unsigned, Node> &getNodes() const;

  bool isFree(unsigned Node) const;

  bool hasEdge(unsigned FromNode, unsigned ToNode) const;

  void dump() const;

  friend std::ostream &operator<<(std::ostream &Stream, MuArchStateGraph Graph) {
  for (const auto &Nd : Graph.getNodes()) {
    Stream << Nd.second;
  }
  return Stream;
  }

  /**
   * The set vertices in the graph.
   * Edges are also contained in this set, each edge has two entries,
   * 	one in the preceding, one in the succeeding Node.
   */
  std::map<unsigned, Node> Nodes;

  /**
   * Map that stores a relation from MBB to Nodes
   */
  std::map<const MachineBasicBlock *, unsigned> MBBToNodeMap;

private:
  /**
   * A counter to give unique identifiers to each Node.
   */
  unsigned NextNodeId;
};

} // end namespace llvm

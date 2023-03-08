/*****************************************************************************
 *
 *  Author:           Dominique Hawkins
 *  Title:            Graphviz Class
 *  Course:           2143
 *  Semester:         Spring 2023
 *
 *  Description:
      Generates a Graphviz graph with "Dot" syntax. It can add nodes, edges, and edges between nodes.
      It gives the option for colored nodes/edges, edge direction, and edge/node shape.
 *        
 *
 *  Usage:
 *    To let the user create a visual representaion of using Graphviz in c++
 *
 * Files: main.cpp
 * Files: test.out
 *****************************************************************************/
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Attribute {
protected:
  map<string, string> att; // attributes

public:
  Attribute() {}

  /**
   * Update an edge attribute. Assumes key is valid.
   */
  void addAttribute(string key, string val) { att[key] = val; }

  /**
   * Takes a map of attributes. Loops over them and saves them
   * locally.
   */
  void addAttributes(map<string, string> atts) {
    for (auto const &x : atts) {
      cout << x.first << "=" << x.second << endl;
      att[x.first] = x.second;
    }
  }
  /**
   * Use our basic print to dump this class out.
   */
  friend ostream &operator<<(ostream &os, Attribute &e) {
    os << "[";
    int i = 0;
    for (auto const &x : e.att) {
      os << x.first << "="
         << "\"" << x.second << "\"";
      if (i < e.att.size() - 1) {
        os << ", ";
      }
      i++;
    }
    os << "]";
    return os;
  }
};


// Class: Edge (inherits from Attribute)
class Edge : public Attribute {

public:
  // Default Constructor
  Edge() {
    att["color"] = "black";    // default color
    att["arrow_type"] = "vee"; // default arrow shape
  }

  // Overloaded constructor
  Edge(string color, string arrow) {
    att["color"] = color;      // default color 
    att["arrow_type"] = arrow; // default arrow shape
  }
};

// Class: Node (inherits from Attribute)
class Node : public Attribute {
public:
  // Default Constructor
  Node() {
    att["color"] = "black"; // default color
    att["shape"] = "box";   // default arrow shape
  }
};

// Class: GraphViz
class GraphViz {
  int edgeId;          // initialize Edge id
  int nodeId;          // initialize Node id
  vector<Edge> Edges;  // creates a vector of Edges 
  vector<Node> Nodes;  // creates a vector of Nodes 

  // Create an Edge Id using start and end points of the edge
  string makeEid(int start, int end) { return to_string(start) + "-" + to_string(end); }

public:
  // Default Constructor
  GraphViz() {
    edgeId = 0;
    nodeId = 0;
  }

  // Function to add node to vector of Nodes
  int addNode() {
    // Pushes 
    Nodes.push_back(Node());
    return Nodes.size() - 1;
  }

  // Function to add edge to vector of Edges
  void addEdge(int start, int end) { 
    Edges.push_back(Edge()); 
  }

  // Output your graphviz stuff
  void printGraph(string graphName) {
    cout << "digraph" << graphName << "{";
    // loop over nodes and print them
    // loop over edges and print them
    cout << "}\n";
  }
};

int main() {
  // This is a hint to include some tracking variables
  int start;
  int end;

  // Example of Vector that holds nodes
  vector<Node> Nodes;

  // We know that the index of the vector = 0-3
  Nodes.push_back(Node());
  Nodes.push_back(Node());
  Nodes.push_back(Node());
  Nodes.push_back(Node());

  // Adds attributes to the nodes using the index of the vector
  Nodes[2].addAttribute("fillColor","purple");
  Nodes[3].addAttribute("fillColor", "red");

  // Example output of dot code
  cout << "digraph" << " Pie" << "{\n";
    // Loops through vector of Nodes and outputs to console
    for(int i=0;i<Nodes.size();i++){
      cout<<"\t"<<i<<" "<<Nodes[i]<<endl;
    }
  cout << "}\n";
 
  return 0;
}

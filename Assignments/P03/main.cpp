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
 * Files: output.txt
 *****************************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

/**
 * Attribute
 *
 * Description:
 *  allows the creation of an att map.
 *
 * Public Methods:
 *      Attribute()
 *      void addAttribute(string key, string val)
 *      void addAttributes(map<string, string> atts)
 *
 * Usage:
 *   map<string, string> Name;
 */
class Attribute {
protected:
  map<string, string> att; // attributes

public:
  Attribute() {}

  /**
   * Updates an edge att
   */
  void addAttribute(string key, string val) { att[key] = val; }

  /**
   * Takes the map of the attributes. Saves and stores them
   * locally.
   */
  void addAttributes(map<string, string> atts) {
    for (auto const &x : atts) {
      att[x.first] = x.second;
    }
  }

  /**
   *print to dump the class out.
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

/**
 * Edge
 *
 * Description:
 *    creates the default/overloaded edge
 *
 * Public Methods:
 *      Edge()
 *      Edge(string color, string arrow, string arrowtail,
 *           string direction, string tailclip)
 *      Edge(int start, int end)
 *
 * Private Methods:
 *      int   eid
 *      int   start
 *      int   end
 *
 */
class Edge : public Attribute {
protected:
  int eid;
  int start;
  int end;

public:
  Edge() {
    att["color"] = "blue"; // defaults
    att["arrowhead"] = "vee";
    att["dir"] = "none";
    att["arrowtail"] = "tee";
  }

  Edge(string color, string arrow, string direction, string arrowtail) {
    att["color"] = color; // overloads atttibutes
    att["arrowhead"] = arrow;
    att["dir"] = direction;
    att["arrowtail"] = arrowtail;
  }
  Edge(int start, int end) {
    this->start = start;
    this->end = end;
  }

  friend ostream &operator<<(ostream &os, Edge &e) {
    os << e.start << " -> " << e.end << " ";
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

/**
 * node
 *
 * Description:
 *    Class creates default node and overloads
 *    it with attributes.
 *
 * Public Methods:
 *    Node(map<string, string> atts)
 *    Node()
 */

class Node : public Attribute {
public:
  Node() {
    att["shape"] = "record"; // default node shape
    att["color"] = "blue";   // default color
  }

  Node(map<string, string> atts) {
    for (auto const &x : atts) {
      att[x.first] = x.second;
    }
  }
};

/**
 * graphViz
 *
 * Description:
 *      Creates an instance of graphviz, can edit nodes and edges.
 *      And it also adds them if neccessary
 *
 * Public Methods:
 *      GraphViz()
 *      int addNode()
 *      void editNode(int id, string key, string value)
 *      void addEdge(int start, int end, map<string, string> att)
 *      void editEdge(int id, string key, string value)
 *
 *
 * Private Methods:
 *        int           nodeId;
 *        int           edgeId;
 *        vector<Node>  Nodes;
 *        vector<Edge>  Edges;
 * Usage:
 *        graphViz G()
 *        G.addNode()
 *        G.addNode(att)
 *        G.editNode(num, string, string)
 *        G.addEdge(num, num)
 *        G.addEdge(num, num, att)
 *        G.editEdge(num, string, string)
 *
 */
class graphViz {
  int nodeId;
  int edgeId;
  vector<Node> Nodes;
  vector<Edge> Edges;

public:
  graphViz() {
    nodeId = 0;
    edgeId = 0;
  }
  //default
  int addNode() {
    Nodes.push_back(Node());
    return Nodes.size() - 1;
  }
  // gives the ability to add nodes
  int addNode(map<string, string> atts) {
    Nodes.push_back(Node(atts));

    return Nodes.size() - 1;
  }
  // gives ability to edit a node
  void editNode(int id, string key, string value) {
    Nodes[id].addAttribute(key, value);
  }
  // gives ability to add edges
  void addEdge(int start, int end) { Edges.push_back(Edge(start, end)); }
  // gives ability to add edges
  void addEdge(int start, int end, map<string, string> att) {

    Edges.push_back(Edge(start, end));
    Edges[Edges.size() - 1].addAttributes(att);
  }
  // gives ability to edit an edge
  void editEdge(int id, string key, string value) {
    Edges[id].addAttribute(key, value);
  }
  //prints the template of graphviz
  friend ostream &operator<<(ostream &os, graphViz &G) {
    os << "digraph "
       << "linkedList"
       << " {\n";
    for (int i = 0; i < G.Nodes.size(); i++) {
      os << i << " " << G.Nodes[i] << endl;
    }
    for (int i = 0; i < G.Edges.size(); i++) {
      os << G.Edges[i] << endl;
    }
    os << "}\n";

    return os;
  }
};

int main() {
  ofstream outfile;
  outfile.open("output.txt");

  // outputting heading
  outfile << "Dominique Hawkins\n";
  outfile << "2143\n";
  outfile << "OOP\n\n";

  // Creates an instance
  graphViz V;

  // Defaults for both edge/node atts
  map<string, string> defEdge;
  
  map<string, string> defNode;
  // Attribute that gets a map of attributes and
  // adds them to "A"
  Attribute A;
  defEdge["color"] = "red";
  defEdge["arrowhead"] = "vee";
  A.addAttributes(defEdge);
  
  defNode["shape"] = "record";
  defNode["color"] = "grey";
  A.addAttributes(defNode);


  // makes the linked list nodes and adds the attributes
  int nodeId = V.addNode(defNode);
  nodeId = V.addNode();
  V.editNode(1, "shape", "box");
  V.editNode(1, "color", "red");
  V.editNode(1, "label", "4");
  nodeId = V.addNode();
  V.editNode(2, "shape", "star");
  nodeId = V.addNode();
  V.editNode(3, "shape", "pentagon");
  V.editNode(3, "color", "black");
  V.editNode(3, "style", "invisible");
  nodeId = V.addNode(defNode);
  V.editNode(4, "label", "{ <data> 56 | <next> }");
  V.editNode(4, "shape", "oval");

  
  //makes the edges and edits them
  V.addEdge(0, 1, defEdge);
  V.editEdge(0, "color", "green");
  V.editEdge(0, "arrowhead", "crow");
  V.editEdge(0, "arrowtail", "dot");
  V.editEdge(0, "dir", "both");
  V.addEdge(1, 2, defEdge);
  V.editEdge(1, "color", "green");
  V.editEdge(1, "arrowhead", "curve");
  V.addEdge(2, 3, defEdge);
  V.editEdge(2, "color", "black");
  V.editEdge(2, "arrowhead", "icurve");
  V.editEdge(2, "dir", "both");
  V.addEdge(3, 4, defEdge);
  V.editEdge(3, "color", "brown");
  V.editEdge(3, "dir", "none");
  V.addEdge(4, 5, defEdge);

  //prints the output file
  outfile << V << endl;
  //closes outfile
  outfile.close();
}

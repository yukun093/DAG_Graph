#include "node.h"

DAG::Node::Node(Data new_data) {
    // Overloaded constructor which sets the data of a node
    data = new_data;
}

void DAG::Node::addNode(std::shared_ptr<Node> node) {
    // Method which adds a node to the list of following nodes of the current node
    Following_Nodes.push_back(node);
}
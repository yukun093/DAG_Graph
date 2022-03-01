#ifndef DAG_NODE_H
#define DAG_NODE_H

#include <vector>
#include <memory>
#include "data.h"
#include <iostream>

namespace DAG {
    class Node {
    public:
        // construct node with data
        Node(Data data);
        // add a successor node
        void addNode(std::shared_ptr<Node> node);
        // Get the Following_Nodes of a Node
        std::vector<std::shared_ptr<DAG::Node>> get_Following_Nodes() const {return Following_Nodes;};
        //Method returns data of the object (for testing)
        Data get_Data() const {return data;};

    private:
        // Data of a node (Name, ID)
        Data data;
        // Vector which contains the following nodes of the current node
        std::vector<std::shared_ptr<DAG::Node>> Following_Nodes;
    };
}

#endif //ALB_NODE_H

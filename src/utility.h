#ifndef DAG_UTILITY_H
#define DAG_UTILITY_H

#include "node.h"
#include <memory>
#include <iostream>
#include <random>

namespace DAG{
    void printGraph(const Node &root, std::ostream &os = std::cout);
    void printGraph_followingNode(const Node &node, std::ostream &os, int n);

    //Function generateRandomPath returns a vector with the nodes of the random path
    std::shared_ptr<Node> generateRandomPath(std::shared_ptr<Node> root);
    
    // create a function to transfer numbers to string
    // std::string num2str(int n);
};

#endif //ALB_UTILITY_H
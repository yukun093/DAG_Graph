#include "utility.h"
#include "node.h"
#include <sstream>
#include <cstdlib>

// next level to print followingNode of one parent Node
void DAG::printGraph_followingNode(const DAG::Node &node, std::ostream &os, int n){
    os << node.get_Data();
    n++;
    os << "\n";
    for (auto item : node.get_Following_Nodes()){
        //Start a new line
        for (int i = 0; i < n; i++)
            os << "\t";
        printGraph_followingNode(*item, os, n);
    }
}

void DAG::printGraph(const Node &root, std::ostream &os/* = std::cout*/){
    // print information of rootNode
    os << root.get_Data();
    // print other nodes
    int n = 1;
    os << "\n";
    for (auto tmp : root.get_Following_Nodes()){
        os << "\t";
        // call another function to print one node
        printGraph_followingNode(*tmp, os, n);
    }
}

// create one random path
std::shared_ptr<DAG::Node> DAG::generateRandomPath(std::shared_ptr<Node> root){
    // create a root node of a random path
    auto randPath = std::make_shared<DAG::Node>(DAG::Data{ root->get_Data().id, root->get_Data().name });

    // to randomize a path
    int rand_n = 0;

    // get all nodes follow the one parentNode, such as rootNode, first create one vector to store all nodes
    std::vector<std::shared_ptr<DAG::Node>> node = root->get_Following_Nodes();
    auto parentNode = randPath;
    for (;;){
        // no child nodes, the path ends
        if (node.empty()) break;

        // generate a random number from 0 - 3
        rand_n = rand() % node.size();

        auto randNode = std::make_shared<DAG::Node>(DAG::Data{ node[rand_n]->get_Data().id, node[rand_n]->get_Data().name });
        parentNode->addNode(randNode);

        // update node, and get a following node of next level as one new parentNode
        node = node[rand_n]->get_Following_Nodes();
        // new parentNode is the randNode which created beforehand
        parentNode = randNode;
    }
    return randPath;
}

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN  // This tells doctest to provide a main() - only do this in one cpp file

#include "doctest.h"
#include "node.h"
#include "utility.h"
#include "data.h"
#include <iostream>

TEST_CASE("Check correctness of implementation files"){
    std::shared_ptr<DAG::Node> FD, FD_;
    std::ostringstream oss;
    std::ostringstream oss_;

    auto rootNode = std::make_shared<DAG::Node>(DAG::Data{1, "A"});
    auto node2 = std::make_shared<DAG::Node>(DAG::Data{2, "B"});
    rootNode->addNode(node2);
    auto node3 = std::make_shared<DAG::Node>(DAG::Data{3, "C"});
    node2->addNode(node3);
    auto node4 = std::make_shared<DAG::Node>(DAG::Data{4, "D"});
    node2->addNode(node4);
    auto node5 = std::make_shared<DAG::Node>(DAG::Data{5, "E"});
    node3->addNode(node5);

    if (node2->get_Data().id != node3->get_Data().id || node2->get_Data().name != node2->get_Data().name){
        FD = node2;
        FD_ = node3;
        DAG::printGraph(*FD, oss);
        DAG::printGraph(*FD_, oss_);
        CHECK(oss.str() == "-> Id: 2, Name: B\n\t-> Id: 3, Name: C\n\t\t-> Id: 5, Name: E\n\t-> Id: 4, Name: D\n");
        CHECK(oss_.str() == "-> Id: 3, Name: C\n\t-> Id: 5, Name: E\n");
    }
}

TEST_CASE("Check correctness of operator"){
    SUBCASE("Check correctness of operator<<"){
        std::ostringstream out;
        auto d = std::make_shared<DAG::Node>(DAG::Data{1, "A"});
        out << d->get_Data().id;
        CHECK(out.str() == "1");
    }

TEST_CASE("Check correctness of operator"){
   SUBCASE("Check correctness of operator<<"){
       std::ostringstream out;
       auto d = std::make_shared<DAG::Node>(DAG::Data{1, "A"});
       std::cout << out.str();
       // out << d->get_Data().id;
   }

   SUBCASE("Check correctness of operator=="){
       DAG::Data node1 = {1, "A"};
       DAG::Data node2 = {1, "A"};
       bool b;
       b = (node1 == node2);
       CHECK(b == true);
   }

   SUBCASE("Check correctness of operator=="){
       DAG::Data node1 = {1, "A"};
       DAG::Data node2 = {1, "B"};
       bool b;
       b = (node1 == node2);
       CHECK(b == false);
   }

   SUBCASE("Check correctness of operator=="){
       DAG::Data node1 = {1, "B"};
       DAG::Data node2 = {1, "A"};
       bool b;
       b = (node1 == node2);
       CHECK(b == false);
   }

   SUBCASE("Check correctness of operator=="){
       DAG::Data node1 = {1, "B"};
       DAG::Data node2 = {1, "B"};
       bool b;
       b = (node1 == node2);
       CHECK(b == true);
   }

   SUBCASE("Check correctness of operator=="){
       DAG::Data node1 = {2, "A"};
       DAG::Data node2 = {2, "A"};
       bool b;
       b = (node1 == node2);
       CHECK(b == true);
   }

   SUBCASE("Check correctness of operator=="){
       DAG::Data node1 = {2, "A"};
       DAG::Data node2 = {2, "B"};
       bool b;
       b = (node1 == node2);
       CHECK(b == false);
   }

   SUBCASE("Check correctness of operator=="){
       DAG::Data node1 = {2, "B"};
       DAG::Data node2 = {2, "A"};
       bool b;
       b = (node1 == node2);
       CHECK(b == false);
   }

   SUBCASE("Check correctness of operator=="){
       DAG::Data node1 = {2, "B"};
       DAG::Data node2 = {2, "B"};
       bool b;
       b = (node1 == node2);
       CHECK(b == true);
   }
}

TEST_CASE("Get data of node"){
    // get rootNode's information
    DAG::Data data1 = {1, "A"};
    bool flag = (data1.id == 1) && (data1.name == "A");
    CHECK(flag == true);
}

TEST_CASE("Get following nodes"){
    auto rootNode = std::make_shared<DAG::Node>(DAG::Data{1, "A"});
    auto node2 = std::make_shared<DAG::Node>(DAG::Data{2, "B"});
    auto node3 = std::make_shared<DAG::Node>(DAG::Data{3, "C"});
    rootNode->addNode(node2);
    rootNode->addNode(node3);
    std::vector<int> d;
    bool flag;
    for (auto tmp : rootNode->get_Following_Nodes()){
        d.push_back(tmp->get_Data().id);
    }
    int dl;
    dl = d.size();
    CHECK((dl == 2) == true);
}

TEST_CASE("printGraph, Simple graph with two nodes"){
    //Test the method printGraph(). Print a simple graph with a root node and one following node
    //Initalize two nodes
    auto rootNode = std::make_shared<DAG::Node>(DAG::Data{ 1, "A" });
    auto node2 = std::make_shared<DAG::Node>(DAG::Data{ 2, "B" });
    //Add node2 to rootNode
    rootNode->addNode(node2);
    
    std::ostringstream oss;
    //Call method pringGraph
    DAG::printGraph(*rootNode, oss);
    
    //Check output
    CHECK(oss.str() == "-> Id: 1, Name: A\n\t-> Id: 2, Name: B\n");
}

TEST_CASE("printGraph, Simple graph with more nodes (row)"){
    //Test the method printGraph(). Print a simple graph (row) with the root node and three following nodes.
    
    //Initalize four nodes
    auto rootNode = std::make_shared<DAG::Node>(DAG::Data{ 1, "A" });
    auto node2 = std::make_shared<DAG::Node>(DAG::Data{ 2, "B" });
    auto node3 = std::make_shared<DAG::Node>(DAG::Data{ 3, "C" });
    auto node4 = std::make_shared<DAG::Node>(DAG::Data{ 4, "D" });
    
    //Add node2 to rootNode. Add node3 to node2. Add node4 to node3. 
    rootNode->addNode(node2);
    node2->addNode(node3);
    node3->addNode(node4);
    
    std::ostringstream oss;
    //Call method pringGraph
    DAG::printGraph(*rootNode, oss);

    //Check output
    CHECK(oss.str() == "-> Id: 1, Name: A\n\t-> Id: 2, Name: B\n\t\t-> Id: 3, Name: C\n\t\t\t-> Id: 4, Name: D\n");
}

TEST_CASE("printGraph, Simple graph with more nodes (tree)"){
    //Test the method printGraph(). Print a simple graph (tree) with the root node and three following nodes
    
    //Initalize four nodes
    auto rootNode = std::make_shared<DAG::Node>(DAG::Data{ 1, "A" });
    auto node2 = std::make_shared<DAG::Node>(DAG::Data{ 2, "B" });
    auto node3 = std::make_shared<DAG::Node>(DAG::Data{ 3, "C" });
    auto node4 = std::make_shared<DAG::Node>(DAG::Data{ 4, "D" });

    //Add node2, node3 and node4 to rootNode.
    rootNode->addNode(node2);
    rootNode->addNode(node3);
    rootNode->addNode(node4);

    std::ostringstream oss;
    //Call method pringGraph
    DAG::printGraph(*rootNode, oss);

    //Check output
    CHECK(oss.str() == "-> Id: 1, Name: A\n\t-> Id: 2, Name: B\n\t-> Id: 3, Name: C\n\t-> Id: 4, Name: D\n");
}

TEST_CASE("printGraph, Advanced graph with more nodes"){
    //Test the method printGraph(). Print a advanced graph with the root node and several following nodes
    
    //Initalize nodes
    auto rootNode = std::make_shared<DAG::Node>(DAG::Data{ 1, "A" });
    auto node2 = std::make_shared<DAG::Node>(DAG::Data{ 2, "B" });
    auto node3 = std::make_shared<DAG::Node>(DAG::Data{ 3, "C" });
    auto node4 = std::make_shared<DAG::Node>(DAG::Data{ 4, "D" }); 
    auto node5 = std::make_shared<DAG::Node>(DAG::Data{ 5, "E" });
    auto node6 = std::make_shared<DAG::Node>(DAG::Data{ 6, "F" });
    auto node7 = std::make_shared<DAG::Node>(DAG::Data{ 7, "G" }); 
    auto node8 = std::make_shared<DAG::Node>(DAG::Data{ 8, "H" });
    auto node9 = std::make_shared<DAG::Node>(DAG::Data{ 9, "I" });
    
    //Add nodes together
    rootNode->addNode(node2);
    rootNode->addNode(node3);
    node2->addNode(node3);
    node2->addNode(node5);
    node3->addNode(node4);
    node3->addNode(node9);
    node4->addNode(node6);
    node5->addNode(node7);
    node7->addNode(node6);
    node7->addNode(node8);
    node8->addNode(node9);

    std::ostringstream oss;
    //Call method pringGraph
    DAG::printGraph(*rootNode, oss);

    //Check output
    CHECK(oss.str() == "-> Id: 1, Name: A\n\t-> Id: 2, Name: B\n\t\t-> Id: 3, Name: C\n\t\t\t-> Id: 4, Name: D\n\t\t\t\t-> Id: 6, Name: F\n\t\t\t-> Id: 9, Name: I\n\t\t-> Id: 5, Name: E\n\t\t\t-> Id: 7, Name: G\n\t\t\t\t-> Id: 6, Name: F\n\t\t\t\t-> Id: 8, Name: H\n\t\t\t\t\t-> Id: 9, Name: I\n\t-> Id: 3, Name: C\n\t\t-> Id: 4, Name: D\n\t\t\t-> Id: 6, Name: F\n\t\t-> Id: 9, Name: I\n");
}

TEST_CASE("generate one random path"){
    auto rootNode = std::make_shared<DAG::Node>(DAG::Data{1, "A"});
    auto node2 = std::make_shared<DAG::Node>(DAG::Data{2, "B"});
    auto node3 = std::make_shared<DAG::Node>(DAG::Data{3, "C"});
    auto node4 = std::make_shared<DAG::Node>(DAG::Data{4, "D"});
    auto node5 = std::make_shared<DAG::Node>(DAG::Data{5, "E"});

    rootNode->addNode(node2);
    rootNode->addNode(node3);
    rootNode->addNode(node4);
    rootNode->addNode(node5);

    node2->addNode(node4);
    node3->addNode(node4);
    node3->addNode(node5);
    node4->addNode(node5);

    srand(time(NULL));
    auto randPath = DAG::generateRandomPath(rootNode);

    // print a valid random path
    std::ostringstream oss;
    DAG::printGraph(*randPath, oss);
    bool flag = false;    
    if (oss.str() == "-> Id: 1, Name: A\n\t-> Id: 2, Name: B\n\t-> Id: 4, Name: D\n\t-> Id: 5, Name: E\n") flag = true; 
    else if(oss.str() == "-> Id: 1, Name: A\n\t-> Id: 4, Name: D\n\t-> Id: 5, Name: E\n") flag = true;
    else if(oss.str() == "-> Id: 1, Name: A\n\t-> Id: 3, Name: C\n\t-> Id: 4, Name: D\n\t-> Id: 5, Name: E\n") flag = true;
    else if(oss.str() == "-> Id: 1, Name: A\n\t-> Id: 3, Name: C\n\t-> Id: 5, Name: E\n") flag = true;
    else if(oss.str() == "-> Id: 1, Name: A\n\t-> Id: 5, Name: E\n") flag = true;

    CHECK(flag == true);
}
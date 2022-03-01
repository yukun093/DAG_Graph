# DAG_Graph
DAG is package to create a valid random path from one graph. There is one picture as an example.
This is a project done with a teammate, so there are many interactions with commits. Basically, one first create cpp file and another use doctest.h to check its correctness.

# node
It is used to copy the data of a node to constructor and use vector to store nodes.
DAG::Node::Node(Data new_data);
void DAG::Node::addNode(std::shared_ptr<Node> node);
 
# data
it is used to output one node's information and use its id and name to judge the correctness of two nodes.

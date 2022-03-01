# DAG_Graph
DAG is package to create a valid random path from one graph. There is one picture as an example.
This is a project done with a teammate, so there are many interactions with commits. Basically, one first create cpp file and another use doctest.h to check its correctness.

# node
It is used to copy the data of a node to constructor and use vector to store nodes.
DAG::Node::Node(Data new_data);
void DAG::Node::addNode(std::shared_ptr<Node> node);
 
# data
it is used to output one node's information and use its id and name to judge the correctness of two nodes.
std::ostream &DAG::operator<< (std::ostream &os, const Data &dt)
bool DAG::operator== (const Data &lhs, const Data &rhs)
 
# utility
it is used first to get one following node of one parent node.
void DAG::printGraph(const Node &root, std::ostream &os)

it is used then to iterate all following nodes of one node.
void DAG::printGraph_followingNode(const DAG::Node &node, std::ostream)

create one random path
std::shared_ptr<DAG::Node> DAG::generateRandomPath(std::shared_ptr<Node> root)

# dag_test
Basically, for each function in one class, its corresponding test should be done.
there are ten test cases and several sub cases.
## TEST_CASE("Check correctness of implementation files")
it is used to check the correctness of output for classes node and data.
## TEST_CASE("Check correctness of operator")
It is used to check two type of operators, in which one is << and another is ==
### SUBCASE("Check correctness of operator<<")
It is one operator<< , just use one stream to check its correctness.
### SUBCASE("Check correctness of operator==")
when there are two nodes, there are 8 cases to be checked.

## TEST_CASE("Get data of node")
It is used to check its correctness of id as well name of one node.
the logic has been set in node class.

## TEST_CASE("Get following nodes")
It is used to first create one tree, then use use rootNode as one vector to call its relevant function get_Following_Nodes(), then let tmp to further call function get_Data() to push back the node's id or name into vector

## TEST_CASE("printGraph, Simple graph with two nodes")
It is used to first create graph, then use stream to check its corresponding correctness with given string path.
There are 5 cases from simple to complicated as different situations to check the correctness of output of printGraph.

## TEST_CASE("generate one random path")
Create one Directed cyclic graph to be regarded as the source.
Then rand one series on time to create random number.
Using printGraph to output one valid random path.
if the random path belongs to one of the listed path, the initialized bool value would become true, then check the correctness.

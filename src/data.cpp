#include "data.h"
#include <iostream>
#include <string>

std::ostream &DAG::operator<<(std::ostream &os, const Data &dt){
    // overloaded <<-operator
    return os << "-> Id: " << dt.id << ", Name: " << dt.name;
}

bool DAG::operator==(const Data &lhs, const Data &rhs){
    // overloaded ==-operator
    if (lhs.id == rhs.id && lhs.name == rhs.name){
        // ID und the name of the node are equal.
        return true;
    }
    else{
        return false;
    }
}
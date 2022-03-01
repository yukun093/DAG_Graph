#ifndef DAG_DATA_H
#define DAG_DATA_H

#include <ostream>

namespace DAG {
    struct Data {
        int id;
        std::string name;
    };

    // overloaded <<-operator
    std::ostream &operator<<(std::ostream &os, const Data &dt);

    // overloaded ==-operator
    bool operator==(const Data &lhs, const Data &rhs);
}

#endif //ALB_DATA_H
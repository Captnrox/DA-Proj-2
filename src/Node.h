#include <string>
using namespace std;
#ifndef DA_PROJ_2_NODE_H
#define DA_PROJ_2_NODE_H


class Node {
private:
    string _label;

public:
    Node();

    void setLabel(string label);
    string getLabel();
};


#endif //DA_PROJ_2_NODE_H

#include <string>
using namespace std;
#ifndef DA_PROJ_2_EDGECLASS_H
#define DA_PROJ_2_EDGECLASS_H


class EdgeClass {
private:
    string _source;
    string _destination;
    int _distance;

public:
    EdgeClass();
    EdgeClass(string source, string destination, int distance);
    void setSource(string source);
    void setDestination(string destination);
    void setDistance(int distance);
    string getSource();
    string getDestination();
    int getDistance();
};


#endif
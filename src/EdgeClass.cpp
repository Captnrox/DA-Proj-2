
#include "EdgeClass.h"

EdgeClass::EdgeClass() {
    _source = "";
    _destination = "";
    _distance = 0;
}

EdgeClass::EdgeClass(std::string source, std::string destination, int distance) {
    _source = source;
    _destination = destination;
    _distance = distance;
}

string EdgeClass::getSource() {
    return _source;
}

string EdgeClass::getDestination() {
    return _destination;
}

int EdgeClass::getDistance() {
    return _distance;
}

void EdgeClass::setSource(std::string source) {
    _source = source;
}

void EdgeClass::setDestination(std::string destination) {
    _destination = destination;
}

void EdgeClass::setDistance(int distance) {
    _distance = distance;
}
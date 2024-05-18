#ifndef DA_PROJ_2_APP_H
#define DA_PROJ_2_APP_H

#include "FileManager.h"

class App{
public:
    App();
    void BTA();
    void OTH();
    void pickToyGraph();
    void triangulationToyGraphs();
    void pickMediumGraph();
    void pickRealGraph();
    bool isNumber(string s);
    int getFirstDigit(int number);
};

#endif //DA_PROJ_2_APP_H

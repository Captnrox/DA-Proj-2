#ifndef DA_PROJ_2_GRAPH_H
#define DA_PROJ_2_GRAPH_H

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <iomanip>
#include <set>
#include <string>
#include <vector>
#include <limits>
#include <cmath>
#include <algorithm>


using namespace std;

class Graph{
    int size;
    double** distances;
    unordered_map<unsigned int, pair<double, double>> coords;
    vector<vector<int>> adj;
    vector<bool> visited;
public:
    Graph(int n, set<vector<string>> edges, unordered_map<unsigned int, pair<double, double>> coords = {});
    double getDist(int a, int b);
    void kruskal();
    void resetGraph();
    //void dfs();
};


#endif //DA_PROJ_2_GRAPH_H

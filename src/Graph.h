#ifndef DA_PROJ_2_GRAPH_H
#define DA_PROJ_2_GRAPH_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <iomanip>
#include <set>
#include <string>
#include <vector>
#include <limits>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>



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
    void connectAllVertex();
    void kruskal();
    void resetGraph();
    void dfs(int startNode, vector<int> *result);
    void backTracking();
    void recBackTracking(vector<int> &bestTrip, double &bestCost, int currentNode, vector<int> &currentTrip, double &currentCost, long &iterations);
    double calculateTour(vector<int> path);
    void christofides(int startIndex = 0);
    vector<pair<int,int>> minWeightMatching(vector<int> oddVertices);
    vector<int> eulerianCircuit();
    void triangularAproximation(bool realWorld);
    void buildAdjacencyList();
    void bfs(int startNode);
    void extraHeuristic(int node);
};


#endif //DA_PROJ_2_GRAPH_H


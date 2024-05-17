#include "Graph.h"
#include "UFDS.h"
#include <stack>

Graph::Graph(int n, set<vector<std::string>> edges, unordered_map<unsigned int, pair<double, double>> coords): size(n), coords(coords){

    //criar array de arrays (matriz dupla de adjacencia para distancias)
    distances = new double *[n];
    for(int i = 0; i <n; i++){
        distances[i] = new double[n];
    }

    //initializar array com o valor maximo possivel para o double
    for(int i = 0; i <n; i++){
        for(int j = 0; j <n; j++){
            distances[i][j] = numeric_limits<double>::max();
        }
    }

    //atualizar valores da matriz para as edges dadas
    for(vector<string>edge: edges){
        distances[stoi(edge[0])][stoi(edge[1])]=stod(edge[2]);
        distances[stoi(edge[1])][stoi(edge[0])]=stod(edge[2]);
    }

    //inicializar is visited e o adj
    vector<int> vector;
    for (int i = 0; i < size; i++){
        adj.push_back(vector);
        visited.push_back(false);
    }

}

double converToRadians(double angle){
    return angle * M_PI/180;
}

double haversine(double lat1, double lon1, double lat2, double lon2) {
    double deltaLat = converToRadians(lat2 - lat1);
    double deltaLon = converToRadians(lon2 - lon1);
    lat1 = converToRadians(lat1);
    lat2 = converToRadians(lat2);
    double a = pow(sin(deltaLat / 2), 2) + pow(sin(deltaLon / 2), 2) * cos(lat1) * cos(lat2);
    double earthRadius = 6371000;
    double c = 2.0 * atan2(sqrt(a), sqrt(1.0-a));
    return earthRadius * c;
}

void Graph::connectAllVertex() {
    double length = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) continue;
            if (distances[i][j] != std::numeric_limits<double>::max()) continue;
            length = haversine(coords[i].first, coords[i].second, coords[j].first, coords[j].second);
            distances[i][j] = length;
            distances[j][i] = length;
        }
    }
}

double Graph::getDist(int a, int b) {
    return distances[a][b];
}

void Graph::resetGraph(){
    vector<int> vector;
    for (int i = 0; i < size; i++){
        adj[i] =vector;
        visited[i] = false;
    }
}

void Graph::kruskal() {
    UFDS ufds(size);
    vector< pair <pair<int, int>, double>> edges;

    this->resetGraph();

    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            edges.emplace_back(make_pair(make_pair(i,j),distances[i][j]));
        }
    }

    sort(edges.begin(),edges.end(),[](const pair <pair<int, int>, double> a, const pair <pair<int, int>, double> b){
        return a.second < b.second;
    });

    int nEdges = 1;
    for(auto e: edges){
        int orig = e.first.first;
        int dest = e.first.second;

        if(!ufds.isSameSet(orig,dest)){
            ufds.linkSets(orig, dest);
            adj[orig].push_back(dest);
            adj[dest].push_back(orig);
            if (nEdges++ == size - 1) {
                break;
            }
        }
    }
}

void Graph::dfs(int startNode, vector<int> *result){
    visited[startNode] = true;
    result->push_back(startNode);

    for(int v: adj[startNode]){
        if(!visited[v]){
            dfs(v, result);
        }
    }
}

double Graph::calculateTour(const vector<int> &path) {
    double distance = 0;
    for (int i = 0; i < path.size() - 1; i++) distance += distances[path[i]][path[i + 1]];
    distance += distances[path[path.size() - 1]][path[0]];
    return distance;
}

vector<int> Graph::christofides() {
    kruskal();

    vector<int> oddVertices;
    for(int i = 0; i < size; i++){
        if(adj[i].size()%2 != 0){
            oddVertices.push_back(i);
        }
    }

    vector<pair<int,int>> perfectMatching = minWeightMatching(oddVertices);

    for(auto e: perfectMatching){
        adj[e.first].push_back(e.second);
        adj[e.second].push_back(e.first);
    }

    vector<int> circuit = eulerianCircuit();
    vector<int> newCircuit;
    vector<bool> visited(size, false);

    for (auto &vertex : circuit) {
        if (!visited[vertex]) {
            newCircuit.push_back(vertex);
            visited[vertex] = true;
        }
    }

    //need to turn graph back to normal

    return newCircuit;
}

vector<pair<int,int>> Graph::minWeightMatching(vector<int> oddVertices) {
    vector<pair<int, int>> minWeightMatching;
    while (!oddVertices.empty()) {
        int v = oddVertices.back();
        oddVertices.pop_back();
        double shortest = numeric_limits<double>::max();
        int shortestIndex = -1;
        for (int i = 0; i < oddVertices.size(); i++) {
            int u = oddVertices[i];
            if (distances[v][u] < shortest) {
                shortest = distances[v][u];
                shortestIndex = i;
            }
        }
        minWeightMatching.push_back(make_pair(v, oddVertices[shortestIndex]));
        minWeightMatching.push_back(make_pair(oddVertices[shortestIndex], v));
        oddVertices.erase(oddVertices.begin() + shortestIndex);
    }
    return minWeightMatching;
}

vector<int> Graph::eulerianCircuit() {
    vector<int> circuit;
    stack<int> stack;
    stack.push(0);

    while (!stack.empty()) {
        int v = stack.top();
        if (adj[v].empty()) {
            circuit.push_back(v);
            stack.pop();
        } else {
            int u = adj[v].back();
            adj[v].pop_back();
            for (int i = 0; i < adj[u].size(); i++) {
                if (adj[u][i] == v) {
                    adj[u].erase(adj[u].begin() + i);
                    break;
                }
            }
            stack.push(u);
        }
    }
    return circuit;
}
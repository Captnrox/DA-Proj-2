#include "Graph.h"
#include "UFDS.h"
#include <chrono>

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

}

double Graph::getDist(int a, int b) {
    return distances[a][b];
}

void Graph::resetGraph(){
    vector<int> vector;
    for (int i = 0; i < size; i++){
        adj.push_back(vector);
        visited.push_back(false);
    }
}

double converToRadians(double angle){
    return angle * M_PI/180;
}

double Haversine(double lat1, double lon1, double lat2, double lon2) {
    double deltaLat = converToRadians(lat2 - lat1);
    double deltaLon = converToRadians(lon2 - lon1);
    lat1 = converToRadians(lat1);
    lat2 = converToRadians(lat2);
    double a = pow(sin(deltaLat / 2), 2) + pow(sin(deltaLon / 2), 2) * cos(lat1) * cos(lat2);
    double earthRadius = 6371000;
    double c = 2.0 * atan2(sqrt(a), sqrt(1.0-a));
    return earthRadius * c;
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
            adj[orig].push_back(dest);
            adj[dest].push_back(orig);
            if (nEdges++ == size - 1) {
                break;
            }
        }
    }
}

//void Graph::dfs();

/**
 * @brief BackTracking algorithm for finding the best cost path in a graph
 *  Makes use of an auxiliary recursive function
 * @return void
 */
void Graph::backTracking() {
    auto start = chrono::high_resolution_clock::now();

    vector<int> currentTrip = {0};
    double currentCost = 0;
    vector<int> bestTrip;
    double bestCost = numeric_limits<double>::max();

    recBackTracking(currentTrip, currentCost, 0, bestTrip, bestCost);

    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "\nO melhor encontrado é: ";
    for (int node = 0; node < bestTrip.size() -1; node++) {
        cout << bestTrip[node] << "->";
    }
    cout << bestTrip[bestTrip.size()-1];
    cout << "\nCom custo total de: " << bestCost;
    cout << "\nNum tempo de: " << duration.count() << " segundos\n";
}


/**
 * @brief Recursive auxiliary function for finding the best cost path
 * @param currentTrip   Nodes visited for the curenth path
 * @param currentCost   Cost of the current path being traversed
 * @param currNode  Current node whose adjacents are being visisted
 * @param bestTrip  Best path found so far
 * @param bestCost  Cost of the best path found
 */
void Graph::recBackTracking(vector<int> &currentTrip, double &currentCost, int currNode, vector<int> &bestTrip, double &bestCost) {

    if (currentTrip.size() == size && currNode == 0) {
        if (currentCost < bestCost) {
            bestTrip = currentTrip;
            bestCost = currentCost;
        }
        return;
    }

    while (currentTrip.size() != size + 1 && currNode != 0) {
        for (int next: adj[currNode]) {
            if (find(currentTrip.begin(), currentTrip.end(), next) == currentTrip.end()) {
                currentTrip.push_back(next);
                currentCost += distances[currNode][next];
                recBackTracking(currentTrip, currentCost, next, bestTrip, bestCost);
                currentTrip.pop_back();
                currentCost -= distances[currNode][next];
            }
        }
    }
}


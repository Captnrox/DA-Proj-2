#include "Graph.h"
#include "UFDS.h"
#include <stack>
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

    //inicializar is visited e o adj
    vector<int> vector;
    for (int i = 0; i < size; i++){
        adj.push_back(vector);
        visited.push_back(false);
    }

}
/**
 * @brief Converts and angle from degrees to radians
 * @param angle Angle to convert
 * @return Returns the angle in radians
 */
double converToRadians(double angle){
    return angle * M_PI/180;
}

/**
 * @brief Calculates the distance between two points given their latitude and longitude
 * @param lat1 Latitude of the first point
 * @param lon1 Longitude of the first point
 * @param lat2 Latitude of the second point
 * @param lon2 Longitude of the second point
 * @return The distance between two points
 */
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
/**
 *  @brief Connects all vertexes, by setting their distance to something other than infinite using the haversine method
 */
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

/**
 * @brief Gets the distance of two points
 * @param a First point
 * @param b Second point
 * @return The distance between two points
 */
double Graph::getDist(int a, int b) {
    return distances[a][b];
}
/**
 * @brief resets the adjacency list and the visited list of nodes for the graph
 */
void Graph::resetGraph(){
    vector<int> vector;
    for (int i = 0; i < size; i++){
        adj[i] =vector;
        visited[i] = false;
    }
}


/**
 * @brief BackTracking algorithm for finding the best cost path in a graph
 *  Makes use of an auxiliary recursive function
 * @return void
 */
void Graph::backTracking() {
    buildAdjacencyList();

    long iterations = 0;
    vector<int> currentTrip = {0};
    vector<int> bestTrip = {};
    double currentCost = 0.0;
    double bestCost = numeric_limits<double>::max();

    auto start = chrono::high_resolution_clock::now();

    recBackTracking(bestTrip, bestCost, 0, currentTrip, currentCost, iterations);

    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    if (bestTrip.empty()) {
        cout << "Error, empty trip\n";
        return;
    }
    cout << "\nBest found path: ";
    for (int node = 0; node < bestTrip.size() -1; node++) {
        cout << bestTrip[node] << " -> ";
    }
    cout << bestTrip[bestTrip.size()-1];
    cout << "\nDistance: " << fixed << setprecision(2)<< bestCost <<endl ;
    cout << "\nTime taken: " << duration.count() << "seconds" << " \n";
}


/**
 * @brief Recursive auxiliary function for finding the best cost path
 * @param bestTrip  Best path found so far
 * @param bestCost  Cost of the best path found
 * @param currentTrip   Nodes visited for the curenth path
 * @param currentCost   Cost of the current path being traversed
 * @param currentNode  Current node whose adjacents are being visisted
 */
void Graph::recBackTracking(vector<int> &bestTrip, double &bestCost, int currentNode, vector<int> &currentTrip, double &currentCost, long &iterations) {

    if (currentTrip.size() == (size +1) && currentNode == 0) {
        if (iterations > tgamma(size)/2) {
            cout << "Error: Excessive iterations";
            return;
        }
        iterations++;
        if (currentCost < bestCost) {
            bestTrip = currentTrip;
            bestCost = currentCost;
        }
        return;
    }

    //Traverse all possible paths starting a currentNode
    for (int next: adj[currentNode]) {
        if ((next == 0 && currentTrip.size() == size) || find(currentTrip.begin(), currentTrip.end(), next) == currentTrip.end()) {
            currentTrip.push_back(next);
            double nextCost = currentCost + distances[currentNode][next];
//currentCost += distances[currentNode][next];
            recBackTracking(bestTrip, bestCost, next, currentTrip, nextCost, iterations);
            currentTrip.pop_back();
//currentCost -= distances[currentNode][next];
        }
        else continue;
    }
}


/**
 * @brief Uses the kruskal algorithm to create an mst
 */
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

/**
 * @brief Algorithm used to iterate over the adjacency matrix
 **/
void Graph::dfs(int startNode, vector<int> *result){
    visited[startNode] = true;
    result->push_back(startNode);

    for(int v: adj[startNode]){
        if(!visited[v]){
            dfs(v, result);
        }
    }
}

/**
 * @brief Calculates the total distance of a TSP path
 * @param path List of ordered nodes that represent the order of nodes to visit
 * @return Returns total distance of the path
 */
double Graph::calculateTour(const vector<int> path) {
    double distance = 0;
    cout << "Path: " << path[0] << " -> ";
    for (int i = 0; i < path.size() - 2; i++){
        cout << path[i +1] << " -> ";
        distance += distances[path[i]][path[i + 1]];
    }
    cout << path[0] << "\n";
    distance += distances[path[path.size() - 1]][path[0]];
    return distance;
}

/**
 * @brief Implements the Christofides algorithm for the Travelling Salesman Problem.
 *
 * The Christofides algorithm is an approximation algorithm for the Travelling Salesman Problem.
 * It guarantees that the length of the tour is within 1.5 times the optimal.
 *
 * The algorithm works as follows:
 * 1. Create a minimum spanning tree of the graph.
 * 2. Find all vertices that have odd degree in the MST.
 * 3. Find a minimum weight perfect matching of these vertices.
 * 4. Combine the edges of the MST and the matching to form a multigraph.
 * 5. Form an Eulerian circuit on this multigraph.
 * 6. Make the circuit into a Hamiltonian circuit by skipping any vertex visited more than once.
 *
 * @return void
 */
void Graph::christofides(int startIndex) {
    auto start = chrono::high_resolution_clock::now();

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

    auto it = find(circuit.begin(), circuit.end(), startIndex);

    rotate(circuit.begin(), it, circuit.end());

    for (auto &vertex : circuit) {
        if (!visited[vertex]) {
            newCircuit.push_back(vertex);
            visited[vertex] = true;
        }
    }

    resetGraph();

    double totalDistance = calculateTour(newCircuit);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "Distance: " << fixed << setprecision(2) << totalDistance << endl;

    cout << "Time take:" << fixed << setprecision(5) << duration.count() << "seconds" << endl;
}

/**
 * @brief Finds a minimum weight perfect matching of the given vertices.
 *
 * A perfect matching is a matching where every vertex is connected to exactly one edge.
 * The function iterates over all vertices and for each vertex, it finds the closest vertex that is not yet matched.
 *
 * @param oddVertices A vector of vertices with odd degree.
 * @return A vector of pairs representing the edges of the matching.
 */
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

/**
 * @brief Finds an Eulerian circuit in the graph.
 *
 * An Eulerian circuit is a circuit that visits every edge exactly once.
 * The function uses a stack to keep track of the vertices. It starts from vertex 0 and while there are unvisited edges,
 * it keeps adding vertices to the stack. When it reaches a vertex with no unvisited edges, it adds the vertex to the circuit.
 *
 * @return A vector representing the Eulerian circuit.
 */
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
/**
 * @brief Finds a TSP path that visits all the nodes of the graph exactly once
 *
 * This is an algorithm is an approximation algorithm for the Travelling Salesman Problem, and works as follows;
 *
 * 1.Create an mst with the nodes of the graph
 * 2.Run over the mst using a dfs and set a path of nodes to follow
 * 3.Knowing the graph is fully connected and that the rule of triangular inequality guarantees that going from one node to another
 * is always better than going back, connect all nodes in order
 * 4.Calculate the size of the path
 * @param realWorld Boolean used to determine if some distances have to be calculated using haversine or not
 */
void Graph::triangularAproximation(bool realWorld){

    auto start = chrono::high_resolution_clock::now();

    vector<int> path;
    if(realWorld){
        connectAllVertex();
    }
    kruskal();
    dfs(0,&path);
    double totalDistance = calculateTour(path);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "Distance: " << fixed << setprecision(2) << totalDistance << endl;

    cout << "Time take:" << fixed << setprecision(5) << duration.count() << "seconds" << endl;

}
/**
 * @brief Builds the adjacency list of a graph based on the distances being available or not, helpful for bfs and dfs
 */
void Graph::buildAdjacencyList() {
    adj.resize(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (distances[i][j] != numeric_limits<double>::max()) {
                adj[i].push_back(j);
            }
        }
    }
}
/**
 * @brief Runs over the adjacency list and visits all nodes to verify if they are all connected
 * @param startNode Starting node for the bfs
 */
void Graph::bfs(int startNode) {
    visited.assign(size, false);
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

/**
 * Applies the heuristic used on 4.3, christofides, after checking if it is possible to connect all vertices through the bfs
 * @param node
 */
void Graph::extraHeuristic(int node){
    auto start = chrono::high_resolution_clock::now();

    buildAdjacencyList();
    bfs(node);
    for(bool visit: visited){
        if(!visit){
            cout << "Not possible to have a path through all nodes";
            return;
        }
    }

    christofides(node);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "Total time take:" << fixed << setprecision(5) << duration.count() << "seconds" << endl;

}
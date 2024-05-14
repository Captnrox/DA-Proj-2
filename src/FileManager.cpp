#include "FileManager.h"

FileManager::FileManager() {};

Graph FileManager::createSimpleGraph(std::string csvName) {
    set<vector<string>> edges;
    int size = 0;
    ifstream file;
    string orig, dest, distance;
    file.open(csvName);
    string line;
    while (getline(file, line)) {

        std::istringstream iss(line);
        std::string token;
        std::vector<std::string> tokens;

        //split the line by commas and store each token
        while (std::getline(iss, token, ',')) {
            tokens.push_back(token);
        }

        //check if the line has at least three values
        if (tokens.size() >= 3) {
            orig = tokens[0];
            dest = tokens[1];
            distance = tokens[2];

            size = max(size, max(stoi(orig), stoi(dest)));
            edges.insert({orig,dest,distance});
        }
    }
    file.close();
    size++;
    Graph toyGraph = Graph(size,edges);
    return toyGraph;
}

Graph FileManager::createGraphWithLabels(std::string csvName) {
    // TODO: Map label to dis
    set<vector<string>> edges;
    int size = 0;
    ifstream file;
    string orig, dest, distance, labelA, labelB;
    file.open(csvName);
    string line;
    while (getline(file, line)) {

        std::istringstream iss(line);
        std::string token;
        std::vector<std::string> tokens;

        //split the line by commas and store each token
        while (std::getline(iss, token, ',')) {
            tokens.push_back(token);
        }

        //check if the line has at least fixe values
        if (tokens.size() >= 5) {
            orig = tokens[0];
            dest = tokens[1];
            distance = tokens[2];
            labelA = tokens[3];
            labelB = tokens[4];

            size = max(size, max(stoi(orig), stoi(dest)));
            edges.insert({orig,dest,distance});
        }
    }
    file.close();
    size++;
    Graph toyGraph = Graph(size,edges);
    return toyGraph;
}

Graph FileManager::createComplexGraph(std::string csvNodes, std::string csvEdges) {
    unordered_map<unsigned int, pair<double, double>> coords;
    set<vector<string>> edges;

    int size = 0;
    ifstream file,file2;
    string id,lon,lat,orig,dest,distance;
    string line;

    file.open(csvNodes);
    while (getline(file, line)) {

        std::istringstream iss(line);
        std::string token;
        std::vector<std::string> tokens;

        //split the line by commas and store each token
        while (std::getline(iss, token, ',')) {
            tokens.push_back(token);
        }

        //check if the line has at least fixe values
        if (tokens.size() >= 3) {
            id = tokens[0];
            lon = tokens[1];
            lat = tokens[2];

            size = max(size,stoi(id));
            coords[stoi(id)] = make_pair(stod(lon),stod(lat));
        }
    }
    file.close();
    size++;

    file2.open(csvEdges);
    while (getline(file2, line)) {

        std::istringstream iss(line);
        std::string token;
        std::vector<std::string> tokens;

        //split the line by commas and store each token
        while (std::getline(iss, token, ',')) {
            tokens.push_back(token);
        }

        //check if the line has at least fixe values
        if (tokens.size() >= 3) {
            orig = tokens[0];
            dest = tokens[1];
            distance = tokens[2];

            edges.insert({orig,dest, distance});
        }
    }
    file.close();

    Graph graph = Graph(size, edges, coords);
    return graph;

}

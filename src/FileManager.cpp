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
}
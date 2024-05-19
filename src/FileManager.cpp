#include "FileManager.h"

FileManager::FileManager() {};

Graph FileManager::createSimpleGraph(std::string csvName) {
    set<vector<string>> edges;
    int size = 0;
    ifstream file;
    string orig, dest, distance;
    file.open(csvName);
    string line;
    getline(file, line);
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
    getline(file, line);
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
    getline(file, line);
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
    getline(file2, line);
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

Graph FileManager::chooseGraph(int csv) {
    switch (csv) {
        case 0:
            return createSimpleGraph("../data/Toy-Graphs/shipping.csv");
        case 1:
            return createSimpleGraph("../data/Toy-Graphs/stadiums.csv");
        case 2:
            return createGraphWithLabels("../data/Toy-Graphs/tourism.csv");
        case 3:
            return createComplexGraph("../data/Real-world Graphs/graph1/nodes.csv", "../data/Real-world Graphs/graph1/edges.csv");
        case 4:
            return createComplexGraph("../data/Real-world Graphs/graph2/nodes.csv", "../data/Real-world Graphs/graph2/edges.csv");
        case 5:
            return createComplexGraph("../data/Real-world Graphs/graph3/nodes.csv", "../data/Real-world Graphs/graph3/edges.csv");
        case 25:
            return createSimpleGraph("../data/Extra_Fully_Connected_Graphs/edges_25.csv");
        case 50:
            return createSimpleGraph("../data/Extra_Fully_Connected_Graphs/edges_50.csv");
        case 75:
            return createSimpleGraph("../data/Extra_Fully_Connected_Graphs/edges_75.csv");
        case 100:
            return createSimpleGraph("../data/Extra_Fully_Connected_Graphs/edges_100.csv");
        case 200:
            return createSimpleGraph("../data/Extra_Fully_Connected_Graphs/edges_200.csv");
        case 300:
            return createSimpleGraph("../data/Extra_Fully_Connected_Graphs/edges_300.csv");
        case 400:
            return createSimpleGraph("../data/Extra_Fully_Connected_Graphs/edges_400.csv");
        case 500:
            return createSimpleGraph("../data/Extra_Fully_Connected_Graphs/edges_500.csv");
        case 600:
            return createSimpleGraph("../data/Extra_Fully_Connected_Graphs/edges_600.csv");
        case 700:
            return createSimpleGraph("../data/Extra_Fully_Connected_Graphs/edges_700.csv");
        case 800:
            return createSimpleGraph("../data/Extra_Fully_Connected_Graphs/edges_800.csv");
        case 900:
            return createSimpleGraph("../data/Extra_Fully_Connected_Graphs/edges_900.csv");
        default:
            return createGraphWithLabels("../data/Toy-Graphs/tourism.csv");
    }
}

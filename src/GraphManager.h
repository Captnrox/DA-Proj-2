#include "Graph.h"
#include "FileManager.h"
#include "Node.h"
#include "EdgeClass.h"
using namespace std;
#ifndef DA_PROJ_2_GRAPHMANAGER_H
#define DA_PROJ_2_GRAPHMANAGER_H


class GraphManager {
private:
    int _datasetChoice;
    FileManager _fileManager;
    Graph<Node> _graph;
    vector<Node> _nodes;
    vector<EdgeClass> _edges;

public:
    GraphManager();
    void makeToyNodes();
    void makeEdges();

    int getDatasetChoice();
};



#endif
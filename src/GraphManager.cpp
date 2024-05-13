#include "GraphManager.h"

GraphManager::GraphManager() {
    _fileManager = FileManager();
    _datasetChoice = _fileManager.getDatasetChoice();
}

int GraphManager::getDatasetChoice() {
    return _datasetChoice;
}

void GraphManager::makeToyNodes() {

}

void GraphManager::makeEdges() {
    auto edgeInfo = _fileManager.getToyGraphVector();
    if (_datasetChoice == 1 || _datasetChoice == 2) {
        for (int i = 0; i < edgeInfo.size(); i + 3) {
            EdgeClass edge = EdgeClass();
            edge.setSource(edgeInfo[i]);
            edge.setDestination(edgeInfo[i + 1]);
            edge.setDistance(stoi(edgeInfo[i + 2]));
            _edges.push_back(edge);
        }
    }
    if (_datasetChoice == 3) {
        for (int i = 0; i < edgeInfo.size(); i + 5) {
            EdgeClass edge = EdgeClass();
            edge.setSource(edgeInfo[i]);
            edge.setDestination(edgeInfo[i + 1]);
            edge.setDistance(stoi(edgeInfo[i + 2]));
            _edges.push_back(edge);
        }
    }
}
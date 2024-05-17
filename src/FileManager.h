#ifndef DA_PROJ_2_FILEMANAGER_H
#define DA_PROJ_2_FILEMANAGER_H

#include "Graph.h"

class FileManager{
public:
    FileManager();
    Graph createSimpleGraph(string csvName);
    Graph createGraphWithLabels(string csvName);
    Graph createComplexGraph(string csvNodes, string csvEdges);
};



#endif //DA_PROJ_2_FILEMANAGER_H

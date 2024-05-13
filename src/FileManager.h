#include <vector>
#include <string>
using namespace std;
#ifndef DA_PROJ_1_FILEMANAGER_H
#define DA_PROJ_1_FILEMANAGER_H

class FileManager {
private:
    int _datasetChoice;
    vector<string> _toyGraphVector;

public:
    FileManager();

    void askForDataSet();
    void askForToyGraph();

    void toyGraph1Chosen();
    void toyGraph2Chosen();
    void toyGraph3Chosen();

    int getDatasetChoice();
    vector<string> getToyGraphVector();

    vector<string> filetoVector(string filename);

};


#endif //DA_PROJ_1_FILEMANAGER_H
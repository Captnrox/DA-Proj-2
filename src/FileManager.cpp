#include "FileManager.h"
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;


FileManager::FileManager() {
    askForDataSet();
}


void FileManager::askForDataSet() {
    cout << "What dataset would you like to build?" << endl
         << "1. Toy Graphs" << endl
         << "Please select an option (number): ";
    string choice;
    bool done = false;
    while(!done){
        cin >> choice;
        if (choice == "1") {
            askForToyGraph();
            done = true;
        } else {
            cout << endl << "Please choose a possible answer" << endl;
        }
    }
}

void FileManager::askForToyGraph() {
    int choice;
    bool done = false;
    cout << "What toy graph would you like to build?" << endl
         << "1. Toy Graph 1" << endl
         << "2. Toy Graph 2" << endl
         << "3. Toy Graph 3" << endl
         << "Please select an option (number): ";
    while(!done){
        cin>> choice;
        if(choice == 1){
            toyGraph1Chosen();
            done = true;
        } else if(choice == 2){
            toyGraph2Chosen();
            done = true;
        } else if(choice == 3){
            toyGraph3Chosen();
            done = true;
        } else {
            cout << endl << "Please choose a possible answer" << endl;
        }
    }
}


void FileManager::toyGraph1Chosen() {
    _toyGraphVector = filetoVector("../src/csv/Toy-Graphs/shipping.csv");
}

void FileManager::toyGraph2Chosen() {
    _toyGraphVector = filetoVector("../src/csv/Toy-Graphs/stadiums.csv");
}

void FileManager::toyGraph3Chosen() {
    _toyGraphVector = filetoVector("../src/csv/Toy-Graphs/tourism.csv");
}

/**
 * @brief Turns a file with the name given into a vector with all strings separated by commas and newliens as an iteration in it
 * @param filename
 * @return Returns a vector of strings with all the file content
 */
vector<string> FileManager::filetoVector(std::string filename) {
    vector<string> res;

    ifstream file;
    file.open(filename);
    string line;
    string word;
    getline(file, line);

    while(getline(file, line)){
        stringstream ss(line);

        while(getline(ss, word, ',')) res.push_back(word);
    }
    return res;
}

int FileManager::getDatasetChoice() {
    return _datasetChoice;
}

vector<string> FileManager::getToyGraphVector() {
    return _toyGraphVector;
}
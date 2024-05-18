#include "app.h"

int option = 0;
bool check = true;
FileManager fM;


App::App() {
    std::string choice = "1";
    do {
        if (check) {
            std::cout << "+-----------------------------------------------------+\n"
                         "|                         Menu                        |\n"
                         "+-----------------------------------------------------+\n"
                         "|        1) Backtracking Algorithm                    |\n"
                         "|        2) Triangular Approximation Heuristic        |\n"
                         "|        3) Christofides                              |\n"
                         "|        4) Real World Cases                          |\n"
                         "|        0) Exit                                      |\n"
                         "+-----------------------------------------------------+\n\n";
            check = false;
        }
        std::cout << "Option: ";
        std::getline(std::cin, choice);
        std::cout << "\n";
        if (choice.length() != 1) std::cout << "Insert a valid option\n\n";
        else {
            switch (choice[0]) {
                case '0':
                    std::cout << "See you later!\n";
                    break;
                case '1':
                    check = true;
                    option = 1;
                    BTA();
                    break;
                case '2': {
                    check = true;
                    option = 2;
                    OTH();
                    break;
                }
                case '3': {
                    check = true;
                    option = 3;
                    OTH();
                    break;
                }
                case '4': {
                    check = true;
                    option = 4;
                    pickRealGraph();
                    break;
                }
                default:
                    std::cout << "Insert a valid option\n\n";
                    continue;
            }
        }
    } while (choice[0] != '0');
}

void App::BTA() {
    std::string choice = "1";
    do {
        if (check) {
            std::cout << "+-------------------------------------------------------------+\n"
                         "|                 Choose the size of the graph                |\n"
                         "+-------------------------------------------------------------+\n"
                         "|        1) Small (toy graphs)                                |\n"
                         "|        2) Medium (extra fully-connected medium-size         |\n"
                         "|        graph data sets)                                     |\n"
                         "|        0) Back                                              |\n"
                         "+-------------------------------------------------------------+\n\n";
            check = false;
        }
        std::cout << "Option: ";
        std::getline(std::cin, choice);
        std::cout << "\n";
        if (choice.length() != 1) std::cout << "Insert a valid option\n\n";
        else {
            switch (choice[0]) {
                case '0':
                    check = true;
                    break;
                case '1': {
                    check = true;
                    option = option * 10 + 1;
                    pickToyGraph();
                    choice = "0";
                    break;
                }
                case '2': {
                    check = true;
                    option = option * 10 + 2;
                    pickMediumGraph();
                    choice = "0";
                    break;
                }
                default:
                    std::cout << "Insert a valid option\n\n";
                    continue;
            }
        }
    } while (choice != "0");
}

void App::OTH() {
    string choice = "1";
    do {
        if (check) {
            std::cout << "+-------------------------------------------------------------+\n"
                         "|                 Choose the size of the graph                |\n"
                         "+-------------------------------------------------------------+\n"
                         "|        1) Small (toy graphs)                                |\n"
                         "|        2) Medium (extra fully-connected medium-size         |\n"
                         "|        graph data sets)                                     |\n"
                         "|        3) Large (real-world graphs data set)                |\n"
                         "|        0) Back                                              |\n"
                         "+-------------------------------------------------------------+\n\n";
            check = false;
        }
        cout << "Option: ";
        getline(std::cin, choice);
        cout << "\n";
        if (choice.length() != 1) cout << "Insert a valid option\n\n";
        else {
            switch (choice[0]) {
                case '0':
                    check = true;
                    break;
                case '1':
                    check = true;
                    option = option * 10 + 1;
                    if((getFirstDigit(option)) == 2) triangulationToyGraphs();
                    else{
                        pickToyGraph();
                    }
                    choice = "0";
                    break;
                case '2':
                    check = true;
                    option = option * 10 + 2;
                    pickMediumGraph();
                    choice = "0";
                    break;
                case '3':
                    check = true;
                    option = option * 10 + 3;
                    pickRealGraph();
                    choice = "0";
                    break;
                default:
                    std::cout << "Insert a valid option\n\n";
                    continue;
            }
        }
    } while (choice != "0");
}

void App::pickToyGraph() {
    string choice = "1";
    do {
        if (check) {
            std::cout << "+--------------------------------+\n"
                         "|        Choose the graph        |\n"
                         "+--------------------------------+\n"
                         "|        1) Shipping             |\n"
                         "|        2) Stadiums             |\n"
                         "|        3) Tourism              |\n"
                         "|        0) Back                 |\n"
                         "+--------------------------------+\n\n";
            check = false;
        }
        std::cout << "Option: ";
        std::getline(std::cin, choice);
        std::cout << "\n";
        if (choice.length() != 1) std::cout << "Insert a valid option\n\n";
        else {
            switch (choice[0]) {
                case '0':
                    check = true;
                    break;
                case '1': {
                    check = true;
                    Graph graph = fM.chooseGraph(0);
                    if(getFirstDigit(option) == 1) {
                        graph.backTracking();
                    }
                    else{
                        graph.christofides();
                    }
                }
                case '2': {
                    check = true;
                    Graph graph = fM.chooseGraph(1);
                    if(getFirstDigit(option) == 1) {
                        graph.backTracking();
                    }
                    else{
                        graph.christofides();
                    }
                    break;
                }
                case '3': {
                    check = true;
                    Graph graph = fM.chooseGraph(2);
                    if(getFirstDigit(option) == 1) {
                        graph.backTracking();
                    }
                    else{
                        graph.christofides();
                    }
                }
                default:
                    std::cout << "Insert a valid option\n\n";
                    continue;
            }
        }
    } while (choice != "0");
}

void App::triangulationToyGraphs(){
    string choice = "1";
    do {
        if (check) {
            std::cout << "+--------------------------------+\n"
                         "|        Choose the graph        |\n"
                         "+--------------------------------+\n"
                         "|        1) Stadiums             |\n"
                         "|        2) Tourism              |\n"
                         "|        0) Back                 |\n"
                         "+--------------------------------+\n\n";
            check = false;
        }
        std::cout << "Option: ";
        std::getline(std::cin, choice);
        std::cout << "\n";
        if (choice.length() != 1) std::cout << "Insert a valid option\n\n";
        else {
            switch (choice[0]) {
                case '0':
                    check = true;
                    break;
                case '1': {
                    check = true;
                    Graph graph = fM.chooseGraph(1);
                    graph.triangularAproximation(false);
                    break;
                }
                case '2': {
                    check = true;
                    Graph graph = fM.chooseGraph(2);
                    graph.triangularAproximation(false);
                    break;
                }
                default:
                    std::cout << "Insert a valid option\n\n";
                    continue;
            }
        }
    } while (choice != "0");
}



void App::pickMediumGraph() {
    std::string choice = "1";
    do {
        std::cout << "Insert the number of nodes you what the graph to have (0 to go back): ";
        std::getline(std::cin, choice);
        std::cout << "\n";
        if (choice.length() == 1 && choice[0] == '0') check = true;
        else if (isNumber(choice)) {
            int lst[12] = {25, 50, 75, 100, 200, 300, 400, 500, 600, 700, 800, 900};
            if (std::find(std::begin(lst), std::end(lst), stoi(choice)) != std::end(lst)) {
                check = true;
                Graph graph = fM.chooseGraph(stoi(choice));
                switch(getFirstDigit(option)){
                    case 1:
                        graph.backTracking();
                        break;
                    case 2:
                        graph.triangularAproximation(false);
                        break;
                    case 3:
                        graph.christofides();
                        break;
                    default:
                        break;
                }
                std::cout << "\n\n";
                do {
                    std::cout << "(0 to go back): ";
                    std::getline(std::cin, choice);
                    std::cout << "\n";
                } while (choice != "0");
                break;
            } else
                std::cout
                        << "Graph with that amount of nodes doesn't exist, try any of the following: 25, 50, 75, 100, 200, 300, 400, 500, 600, 700, 800 or 900\n\n";
        } else std::cout << "Insert a number\n\n";
    } while (choice != "0");
}

void App::pickRealGraph() {
    string choice = "1";
    do {
        if (check) {
            std::cout << "+--------------------------------+\n"
                         "|        Choose the graph        |\n"
                         "+--------------------------------+\n"
                         "|        1) Graph1               |\n"
                         "|        2) Graph2               |\n"
                         "|        3) Graph3               |\n"
                         "|        0) Back                 |\n"
                         "+--------------------------------+\n\n";
            check = false;
        }
        std::cout << "Option: ";
        std::getline(std::cin, choice);
        std::cout << "\n";
        if (choice.length() != 1) std::cout << "Insert a valid option\n\n";
        else {
            switch (choice[0]) {
                case '0':
                    check = true;
                    break;
                case '1': {
                    Graph graph = fM.chooseGraph(3);
                    switch(getFirstDigit(option)){
                        case 2:
                            graph.triangularAproximation(true);
                            break;
                        case 3:;
                            graph.christofides();
                            break;
                        case 4:
                            //TODO: final heuristic;
                            break;
                        default:
                            break;
                    }
                    break;
                }
                case '2': {
                    check = true;
                    Graph graph = fM.chooseGraph(4);
                    switch(getFirstDigit(option)){
                        case 2:
                            graph.triangularAproximation(true);
                            break;
                        case 3:;
                            graph.christofides();
                            break;
                        case 4:
                            //TODO: final heuristic;
                            break;
                        default:
                            break;
                    }
                    break;
                }
                case '3': {
                    check = true;
                    Graph graph = fM.chooseGraph(5);
                    switch(getFirstDigit(option)){
                        case 2:
                            graph.triangularAproximation(true);
                            break;
                        case 3:;
                            graph.christofides();
                            break;
                        case 4:
                            //TODO: final heuristic;
                            break;
                        default:
                            break;
                    }
                }
                default:
                    std::cout << "Insert a valid option\n\n";
                    continue;
            }
        }
    } while (choice != "0");
}


bool App::isNumber(std::string s) {
    std::istringstream iss(s);
    int f;
    iss >> f;
    return iss.eof() && !iss.fail();
}

int App::getFirstDigit(int number) {
    std::string numberStr = std::to_string(number);
    char firstChar;

    if (numberStr[0] == '-') {
        firstChar = numberStr[1]; // Skip the negative sign
    } else {
        firstChar = numberStr[0];
    }

    int firstDigit = firstChar - '0';
    return firstDigit;
}
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
                    OTH();
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
                    if((option/10)%10 == 2) triangulationToyGraphs();
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

                    break;
                }
                case '2': {
                    check = true;

                    break;
                }
                case '3': {
                    check = true;

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

                    break;
                }
                case '2': {
                    check = true;

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
                //do stuff here;
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

                    break;
                }
                case '2': {
                    check = true;

                    break;
                }
                case '3': {
                    check = true;

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
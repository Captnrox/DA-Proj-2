app::App() {
    std::string choice = "1";
    do {
        if (check) {
            std::cout << "+-----------------------------------------------------+\n"
                         "|                         Menu                        |\n"
                         "+-----------------------------------------------------+\n"
                         "|        1) Backtracking Algorithm                    |\n"
                         "|        2) Triangular Approximation Heuristic        |\n"
                         "|        3) Extra Algorithm                           |\n"
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
                    //func
                    break;
                case '2': {
                    check = true;
                    option = 2;
                    //func
                    break;
                }
                case '3': {
                    check = true;
                    option = 3;
                    //func;
                    break;
                }
                case '4':{
                    check = true;
                    option 4;
                    //func
                    break;
                }
                default:
                    std::cout << "Insert a valid option\n\n";
                    continue;
            }
        }
    }
    while(choice[0] != '0');
}

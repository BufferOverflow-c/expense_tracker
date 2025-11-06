#include <iostream>

#include "LinkedList.hpp"

// TODO: input checks for arguments

bool isInputValid(int argc, char *argv[]);

int main(int argc, char *argv[]) {
  std::cout << argc << std::endl;

  if (!isInputValid(argc, argv)) {
    return 1;
  }
  LinkedList list;

  return 0;
}

bool isInputValid(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Usage: ./expense_tracker add --description <description> "
                 "--amount <amount>"
              << std::endl;
    std::cout << "Usage: ./expense_tracker remove --id <id>" << std::endl;
    std::cout << "Usage: ./expense_tracker list" << std::endl;
    std::cout << "Usage: ./expense_tracker summary" << std::endl;
    std::cout << "Usage: ./expense_tracker summary --month <month>"
              << std::endl;
    return false;
  }

  if (std::string(argv[1]) == "add" && argc == 6) {
    return true;
  }
  return true;
}

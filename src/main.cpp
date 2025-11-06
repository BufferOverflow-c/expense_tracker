#include <iostream>

#include "LinkedList.hpp"

// TODO: input checks for arguments

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Usage: ./expense_tracker add --description <description> "
                 "--amount <amount>"
              << std::endl;
    std::cout << "Usage: ./expense_tracker remove --id <id>" << std::endl;
    std::cout << "Usage: ./expense_tracker list" << std::endl;
    std::cout << "Usage: ./expense_tracker summary" << std::endl;
    std::cout << "Usage: ./expense_tracker summary --month <month>"
              << std::endl;
    return 1;
  }

  LinkedList list;

  return 0;
}

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "LinkedList.hpp"
#include "Utils.hpp"

// TODO: input checks for arguments
void ensureFileExists(const std::string &rFile_name);
bool isInputValid(int argc, char *argv[]);

int main(int argc, char *argv[]) {
  if (!isInputValid(argc, argv)) {
    return 1;
  }
  ensureFileExists("expenses.json");

  LinkedList list;
  Utils::read("expenses.json", list);

  Utils::write("expenses.json", list);
  return 0;
}

void ensureFileExists(const std::string &rFile_name) {
  if (!std::filesystem::exists(rFile_name)) {
    std::ofstream file(rFile_name);
    if (!file) {
      std::cerr << "Error creating file: " << rFile_name << std::endl;
      file << "[]";
      return;
    }
    std::cout << "File created successfully: " << rFile_name << std::endl;
  }
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

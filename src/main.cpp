#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "LinkedList.hpp"
#include "Utils.hpp"

// TODO: input checks for arguments
void ensureFileExists(const std::string &rFile_name);
bool isInputValid(int argc, char *argv[], LinkedList &list);

int main(int argc, char *argv[]) {
  const std::string FILE_NAME = "expenses.json";
  ensureFileExists(FILE_NAME);

  LinkedList list;
  Utils::read(FILE_NAME, list);

  if (!isInputValid(argc, argv, list)) {
    return 1;
  }

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

bool isInputValid(int argc, char *argv[], LinkedList &list) {
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

  if (argc == 6 && std::string(argv[1]) == "add") {
    std::string description = argv[3];
    double amount = std::stod(argv[5]);
    list.addExpense(description, amount);
    Utils::write("expenses.json", list);
    return true;
  }

  if (argc == 4 && std::string(argv[1]) == "remove") {
    const int id = std::stoi(argv[3]);
    list.removeExpense(id);
    Utils::write("expenses.json", list);
    return true;
  }

  if (argc == 2 && std::string(argv[1]) == "list") {
    list.printAll();
    Utils::write("expenses.json", list);
    return true;
  }

  if (argc == 2 && std::string(argv[1]) == "summary") {
    list.printFullSummary();
    Utils::write("expenses.json", list);
    return true;
  }

  if (argc == 4 && std::string(argv[1]) == "summary" &&
      std::string(argv[2]) == "--month") {
    int month;
    try {
      month = std::stoi(argv[3]);
    } catch (const std::invalid_argument &e) {
      std::cerr << "Invalid month: " << argv[3] << std::endl;
      return false;
    }
    list.printSpecificMonthSummary(month);
    Utils::write("expenses.json", list);
    return true;
  }
  return true;
}

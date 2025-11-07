#pragma once

#include "LinkedList.hpp"
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace Utils {
inline void write(const std::string &rFilename, LinkedList &list) {
  std::ofstream file(rFilename);
  if (!file.is_open()) {
    std::println("Failed to open file for writing.");
    return;
  }
  Node *pCurr = list.pHead;
  while (pCurr) {
    if (pCurr == list.pHead) {
      file << "[\n";
    } else {
      file << ",\n";
    }
    json data = {{"id", pCurr->m_id},
                 {"amount", pCurr->m_amount},
                 {"date", pCurr->m_date},
                 {"description", pCurr->m_description}};
    file << data.dump();
    pCurr = pCurr->pNext;
  }
  file << "\n]";
  file.close();
}

inline void read(const std::string &rFile_name, LinkedList &list) {
  std::ifstream file(rFile_name);
  if (!file.is_open()) {
    std::println("Failed to open file for reading.");
    return;
  }

  if (file.peek() == std::ifstream::traits_type::eof()) {
    std::println("File is empty, nothing to read.");
    file.close();
    return;
  }

  json data = json::parse(file);
  for (int i{}; i < data.size(); i++) {
    list.addExpense(data[i]["description"], data[i]["amount"]);
  }

  file.close();
}
} // namespace Utils

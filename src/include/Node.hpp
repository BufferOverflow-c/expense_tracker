#pragma once

#include <ctime>
#include <string>

struct Node {
  Node *pNext;
  Node *pPrev;
  int m_id;
  int m_amount;
  std::string m_date;
  std::string m_description;

  Node(const std::string &rDescription, const int amount)
      : pNext(nullptr), pPrev(nullptr), m_id(0), m_description(rDescription),
        m_amount(amount) {
    time_t now = time(nullptr);
    tm *local = localtime(&now);

    m_date = std::to_string(local->tm_year + 1900) + "-" +
             std::to_string(local->tm_mon + 1) + "-" +
             std::to_string(local->tm_mday);
  }
};

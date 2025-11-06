#pragma once

#include <string>

struct Node {
  Node *pNext;
  Node *pPrev;
  int m_id;
  int m_amount;
  std::string m_date;
  std::string m_description;

  Node() : pNext(nullptr), pPrev(nullptr) {}
};

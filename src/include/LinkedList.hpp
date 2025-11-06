#pragma once

#include "Node.hpp"

class LinkedList {
public:
  LinkedList();
  ~LinkedList();

  void addExpense(const std::string &rDescription, const int amount);
  void removeExpense(const int id);

  void printAll() const;
  void printFullSummary() const;
  void printSpecificMonthSummary(const int month);

private:
  Node *pHead;
  Node *pTail;
};

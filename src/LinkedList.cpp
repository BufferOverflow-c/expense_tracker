
#include <iostream>
#include <iterator>
#include <ranges>

#include "LinkedList.hpp"

LinkedList::LinkedList() : pHead(nullptr), pTail(nullptr) {}

LinkedList::~LinkedList() {
  Node *current = pHead;
  while (current) {
    Node *next = current->pNext;
    delete current;
    current = next;
  }
}

void LinkedList::addExpense(const std::string &rDescription, const int amount) {
  Node *node = new Node(rDescription, amount);
  if (!pHead) {
    pHead = node;
    pTail = node;
  } else {
    pTail->pNext = node;
    node->m_id = pTail->m_id + 1;
    pTail = node;
  }
}

void LinkedList::removeExpense(const int id) {
  Node *current = pHead;
  Node *previous = pHead;
  while (current) {
    if (current->m_id == id) {
      if (current == pHead) {
        pHead = current->pNext;
        delete current;
        current = pHead;
      } else {
        previous->pNext = current->pNext;
        delete current;
        current = previous->pNext;
      }
    }
    previous = current;
    current = current->pNext;
  }
}

void LinkedList::printAll() const {
  std::cout << "ID    Date    Description    Amount\n";
  Node *current = pHead;
  while (current) {
    std::cout << current->m_id << "    " << current->m_date << "    "
              << current->m_description << "    " << current->m_amount
              << std::endl;
    current = current->pNext;
  }
}

void LinkedList::printFullSummary() const {
  int total{};

  Node *current = pHead;
  while (current) {
    total += current->m_amount;
    current = current->pNext;
  }
  std::cout << "Total expenses: " << total << std::endl;
}

void LinkedList::printSpecificMonthSummary(const int month) {
  int total{};
  Node *current = pHead;
  while (current) {
    auto split = current->m_date | std::ranges::views::split('-');
    auto it = split.begin();
    std::advance(it, 1);
    auto &&subrange = *it;

    std::string m_month(std::ranges::begin(subrange),
                        std::ranges::end(subrange));

    try {
      if (std::stoi(m_month) == month) {
        total += current->m_amount;
      }
    } catch (const std::invalid_argument &e) {
      std::cerr << "Invalid argument: " << e.what() << std::endl;
    }

    current = current->pNext;
  }
  std::cout << "Total expenses for month " << month << ": " << total
            << std::endl;
}

#include "LinkedList.hpp"

LinkedList::LinkedList() : pHead(nullptr), pTail(nullptr) {}
LinkedList::~LinkedList() {}

void LinkedList::addExpense(const std::string &rDescription, const int amount) {
}
void LinkedList::removeExpense(const int id) {}

void LinkedList::printAll() const {}
void LinkedList::printFullSummary() const {}
void LinkedList::printSpecificMonthSummary(const int month) {}

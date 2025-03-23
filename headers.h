#pragma once
#include <iostream>

class ForwardList {
private:
  struct Node {
    double value;
    Node *next;

    Node() : value(0.0), next(nullptr) {}

    Node(double val, Node* nxt = nullptr) : value(val), next(nxt) {}
  };
  Node *head;

public:

  ForwardList() : head(nullptr) {}
  ForwardList(const ForwardList& other);
  ForwardList(ForwardList&& other);
  ForwardList& operator=(const ForwardList& other);
  ForwardList& operator=(ForwardList&& other);
  ~ForwardList();
  void push_front(double value);
  void pop_front();
  const double &front() const;
  size_t size() const;
  bool empty() const;
  void display() const;
  void erase(double value);
  void clear();
};

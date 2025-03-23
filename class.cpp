#include <exception>
#include <iostream>
#include "headers.h"

void ForwardList::push_front(double value)
{
    Node* node = new Node;
    node->value = value;
    node->next = this->head;
    this->head = node;
}
ForwardList :: ForwardList(const ForwardList& other) 
{
  if (other.head == nullptr) {
      return; 
  }

  head = new Node(other.head->value);
  Node* current1 = head;
  Node* current2 = other.head->next;
  while (current2 != nullptr)
  {
    current1->next = new Node(current2->value,nullptr);
    current2 = current2->next;
    current1 = current1->next;
  }
  
}

ForwardList :: ForwardList(ForwardList&& other)
{
    head = other.head;
    other.head = nullptr;
}

ForwardList :: ~ForwardList() {
    while (head != nullptr) {
      Node *temp = head;
      head = head->next;
      delete temp;
    }
  }

ForwardList& ForwardList :: operator=(const ForwardList& other)
  {
    if (this == &other)
    {
      return *this;
    }

    this->clear();
    
    if (other.head != nullptr) 
    {
      head = new Node(other.head->value);
      Node* current1 = head;
      Node* current2 = other.head->next;
      while (current2 != nullptr)
      {
        current1->next = new Node(current2->value,nullptr);
        current2 = current2->next;
        current1 = current1->next;
      }
    }
    return *this;
}

ForwardList& ForwardList :: operator=(ForwardList&& other)
{
    if (this != &other)
    {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        head = other.head;
        other.head = nullptr;
    }
    return *this;
}

void ForwardList::pop_front()
{
    if (this->head == nullptr)
    {
        std::cerr << "Нет у нас головки";
    }
    Node *tmpr = this->head;
    this->head = this->head->next;
    delete tmpr;
}

const double& ForwardList::front() const {
    if (this->head == nullptr) 
    {
        std::cerr << "Список пуст: нет первого элемента";
    }
    return this->head->value;
}

void ForwardList::display() const
{
    Node *current = head;
    while (current != nullptr)
    {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

size_t ForwardList::size() const
{
    size_t cnt = 0;
    Node *current = head;
    while (current != nullptr)
    {
        ++cnt;
        current = current->next;
    }
    return cnt; 
}

bool ForwardList::empty() const
{
    return this->head == nullptr;
}

void ForwardList::clear() {
    while (this->head != nullptr) {
        Node* current = this->head; 
        this->head = this->head->next; 
        delete current;
    }
}

void ForwardList::erase(double value) {
    Node* current = head;
    Node* last = nullptr;

    while (current != nullptr) {
        if (current->value == value) {
            if (last == nullptr) {
                head = current->next;
                delete current;
                current = head;
            } else {
                last->next = current->next;
                delete current;
                current = last->next;
            }
        } else {
            last = current;
            current = current->next;
        }
    }
}

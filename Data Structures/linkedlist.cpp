#include <iostream>
#include <string>

using namespace std;

class Node {
 public:
  int value;
  Node* next;
  Node(int v) : value(v), next(nullptr) {}
};

class LinkedList {
 private:
  Node* root;

 public:
  LinkedList(int v) {
    root = new Node(v);
    return;
  }

  void add(int v) {
    Node* ptr = root;

    while (ptr->next != nullptr) {
      ptr = ptr->next;
    }
    ptr->next = new Node(v);
  }

  friend ostream& operator<<(ostream& os, const LinkedList& list) {
    Node* ptr = list.root;
    while (ptr != nullptr) {
      os << ptr->value << " -> ";
      ptr = ptr->next;
    }
    return os;
  }
};

int main() {
  LinkedList L = LinkedList(3);
  L.add(5);
  L.add(7);
  cout << L;
  return 0;
}
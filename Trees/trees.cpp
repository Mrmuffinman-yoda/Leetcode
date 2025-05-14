#include <iostream>
#include <string>

using namespace std;

class Node {
 public:
  Node* left;
  Node* right;
  int value;
  Node(int currentValue) : left(nullptr), right(nullptr), value(currentValue) {}
};

class BinaryTree {
 public:
  Node* root;

  BinaryTree(int initialValue) { root = new Node(initialValue); }

  ~BinaryTree() { deleteTree(root); }

  // Insert a value into the binary search tree
  void insert(int val) { insertHelper(root, val); }

 private:
  void deleteTree(Node* node) {
    if (node != nullptr) {
      deleteTree(node->left);
      deleteTree(node->right);
      delete node;
    }
  }

  // Helper function for insertion
  void insertHelper(Node* node, int val) {
    if (val < node->value) {
      if (node->left == nullptr) {
        node->left = new Node(val);
      } else {
        insertHelper(node->left, val);
      }
    } else {
      if (node->right == nullptr) {
        node->right = new Node(val);
      } else {
        insertHelper(node->right, val);
      }
    }
  }
};

int main() {
  BinaryTree b = BinaryTree(3);
  b.insert(1);
  b.insert(5);
}
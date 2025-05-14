#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr) return nullptr;

    // go left
    invertTree(root->left);
    // go right
    invertTree(root->right);
    // flip
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;

    return root;
  }
};

int factorial(int n) {
  if (n == 0) {
    return 1;
  }
  return n * factorial(n - 1);
}

int main() { cout << factorial(3); }
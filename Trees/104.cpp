#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int maxDepth(TreeNode *root) {
    // need to recurse into the tree, pass in the curent depth to the next
    // function keep a score of the max depth  for every left / right turn in
    // the tree
    if (root == nullptr) {
      return 0;
    }
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
  }
};
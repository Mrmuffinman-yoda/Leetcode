#include <cmath>

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
  bool isBalanced(TreeNode *root) {
    int difference = calcDepth(root);
    // if difference = -1 , it aint balanaced
    if (difference == -1) return false;
    return true;
  }

  int calcDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    int leftDepth = calcDepth(root->left);
    // if left isn't balanced, we can keep returning -1
    if (leftDepth == -1) return -1;
    int rightDepth = calcDepth(root->right);
    // if right isn't balanced, we can keep returning -1
    if (rightDepth == -1) return -1;

    // check the current node is balanced, if not return -1
    int difference = abs(leftDepth - rightDepth);

    if (difference > 1) return -1;

    // if it is balanced, return the longest length between left and right to
    // check if the node previously is also balanced
    // we don't care about the shorter side as we need the depth to be
    // balanced

    return 1 + max(leftDepth, rightDepth);
  }
};
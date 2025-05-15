#include <cassert>
#include <cmath>
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
  int maxDiameter = 0;
  int diameterOfBinaryTree(TreeNode *root) {
    depth(root);
    return maxDiameter;
  }

  int depth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);

    int diameter = leftDepth + rightDepth;
    maxDiameter = max(maxDiameter,
                      diameter);  // updating diameter, we need to return this

    return 1 + max(leftDepth, rightDepth);  // returning depth not diameter
  }
};

int main() {
  // Example 1:
  //      1
  //     / \
  //    2   3
  //   / \
  //  4   5
  //
  // Diameter = 3 (path: 4 -> 2 -> 1 -> 3)
  TreeNode *root1 = new TreeNode(
      1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));

  // Example 2:
  //      1
  //       \
  //        2
  //         \
  //          3
  //
  // Diameter = 2 (path: 1 -> 2 -> 3)
  TreeNode *root2 =
      new TreeNode(1, nullptr, new TreeNode(2, nullptr, new TreeNode(3)));

  // Example 3:
  //       1
  //      /
  //     2
  //    /
  //   3
  //  /
  // 4
  //
  // Diameter = 3 (path: 4 -> 3 -> 2 -> 1)
  TreeNode *root3 = new TreeNode(
      1, new TreeNode(2, new TreeNode(3, new TreeNode(4), nullptr), nullptr),
      nullptr);

  // Example 4:
  //   1
  //    \
  //     2
  //
  // Diameter = 1 (path: 1 -> 2)
  TreeNode *root4 = new TreeNode(1, nullptr, new TreeNode(2));

  Solution sol;

  sol.maxDiameter = 0;
  sol.diameterOfBinaryTree(root1);
  assert(sol.maxDiameter == 3);

  sol.maxDiameter = 0;
  sol.diameterOfBinaryTree(root2);
  assert(sol.maxDiameter == 2);

  sol.maxDiameter = 0;
  sol.diameterOfBinaryTree(root3);
  assert(sol.maxDiameter == 3);

  sol.maxDiameter = 0;
  sol.diameterOfBinaryTree(root4);
  assert(sol.maxDiameter == 1);

  cout << "All test cases passed!" << endl;

  // Clean up
  delete root1->left->left;
  delete root1->left->right;
  delete root1->left;
  delete root1->right;
  delete root1;

  delete root2->right->right;
  delete root2->right;
  delete root2;

  delete root3->left->left->left;
  delete root3->left->left;
  delete root3->left;
  delete root3;

  delete root4->right;
  delete root4;

  return 0;
}

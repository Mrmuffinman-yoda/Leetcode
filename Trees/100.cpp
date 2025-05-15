#include <climits>
#include <vector>

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
  bool isSameTree(TreeNode *p, TreeNode *q) {
    // create two vectors to save the values:

    vector<int> tree1 = {};
    vector<int> tree2 = {};
    depth(p, tree1);
    depth(q, tree2);

    return tree1 == tree2;
  }

  void depth(TreeNode *root, vector<int> &values) {
    if (root == nullptr) {
      values.push_back(INT_MIN);
      return;
    }

    // go all the way left,
    depth(root->left, values);

    // go all the way right

    depth(root->right, values);

    values.push_back(root->val);
    return;
  }
};
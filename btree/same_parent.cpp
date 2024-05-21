
#include <iostream>

// 236. 二叉树的最近公共祖先
// 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
// 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
// 输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// 输出：3
// 解释：节点 5 和节点 1 的最近公共祖先是节点 3 。

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* same_parent;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p , q);
        return same_parent;
    }

    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
      if (root==nullptr)
      {
        return false;
      }
      bool left = dfs(root->left, p, q);
      bool right = dfs(root->left, p, q);
      std::cout << "root: " << root->val << ", left: " << root->left->val << ", right: " << root->right << std::endl;
      return false;
    }
};

int main() {
  Solution s;
  s.lowestCommonAncestor();
  return 0;
}
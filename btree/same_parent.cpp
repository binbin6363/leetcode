#include <list>
#include <vector>
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

TreeNode *constructTree(std::vector<int> array) {
    if (array.empty()) {
        return nullptr;
    }

    int index = 0;
    int length = array.size();

    TreeNode *root = new TreeNode(array[0]);
    std::list<TreeNode*> nodeQueue;
    nodeQueue.push_back(root);
    TreeNode *currNode = nullptr;
    while (index < length) {
        index++;
        if (index >= length) {
            return root;
        }
        currNode = nodeQueue.front();
        int leftChild = array[index];
        if (leftChild != -1) {
            currNode->left = new TreeNode(leftChild);
            nodeQueue.push_back(currNode->left);
        }
        index++;
        if (index >= length) {
            return root;
        }
        int rightChild = array[index];
        if (rightChild != -1) {
            currNode->right = new TreeNode(rightChild);
            nodeQueue.push_back(currNode->right);
        }
    }

    return root;
}

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

// g++ same_parent.cpp -std=c++11
int main() {
  std::vector<int> array = {3,5,1,6,2,0,8,-1,-1,7,4};
  TreeNode* root = constructTree(array);
  TreeNode* p = new TreeNode(5);
  TreeNode* q = new TreeNode(4);
  Solution s;
  s.lowestCommonAncestor(root, p, q);
  return 0;
}
#include <iostream>
#include <list>
#include "utils/tree.hpp"

using namespace utils;

// 226. 翻转二叉树
// 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
      if (root == nullptr)
      {
        return root;
      }
      
      TreeNode* newTree = new TreeNode(root->val);
      TreeNode* pNewTree = newTree;
      std::list<TreeNode*> nodeList;
      nodeList.push_back(root);
      
      std::list<TreeNode*> newNodeList;
      newNodeList.push_back(pNewTree);

      while (nodeList.back() != nullptr)
      {
        TreeNode* cur = nodeList.back();nodeList.pop_back();
        pNewTree = newNodeList.back(); newNodeList.pop_back();
        std::cout << "show root:" << cur->val << std::endl;
        if (cur->left != nullptr) {
          pNewTree->right = new TreeNode(cur->left->val);
          nodeList.push_back(cur->left);
          newNodeList.push_back(pNewTree->right);
          std::cout << "show left:" << cur->left->val << std::endl;
        } 
        if (cur->right != nullptr) {
          pNewTree->left = new TreeNode(cur->right->val);
          nodeList.push_back(cur->right);
          newNodeList.push_back(pNewTree->left);
          std::cout << "show right:" << cur->right->val << std::endl;
        }
      }
      
      return newTree;
    }

    // 递归版本，直接在原树上修改
    TreeNode* invertTreeRecursion(TreeNode* root) {
      if (root == nullptr) {
        return root;
      }
      
      TreeNode* left = invertTreeRecursion(root->left);
      TreeNode* right = invertTreeRecursion(root->right);

      root->left = right;
      root->right = left;
      return root;
    }
};

int main() {
  std::vector<int> array = {4,2,7,1,3,6,9};
  TreeNode* root = ConstructTree(array);
  Solution s;
  TreeNode* res = s.invertTreeRecursion(root);

  PrintNodeInternal(res, 0, 3);
  
  return 0;
}
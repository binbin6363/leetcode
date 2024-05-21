#include <list>
#include <vector>
#include <iostream>
#include "utils/tree.hpp"

using namespace utils;

// 236. 二叉树的最近公共祖先
// 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
// 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
// 输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// 输出：3
// 解释：节点 5 和节点 1 的最近公共祖先是节点 3 。
class Solution {
public:
  TreeNode* same_parent;
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    dfs(root, p , q);
    return same_parent;
  }

  // 1 存在1个节点，2 存在2个节点，0 不存在节点
  int dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) {
      return 0;
    }
    int inLeftCnt = dfs(root->left, p, q);
    int inRightCnt = dfs(root->right, p, q);

    // 最近公共祖先判断条件：要么两个节点分布在左右子树；要么一个节点在左子树，一个节点在右子树；要么一个节点在根节点上
    if (inLeftCnt == 1 && inRightCnt == 1) {
      std::cout << "found node in both side : "<< root->val <<std::endl;
      same_parent = root;
    } else if ((inLeftCnt == 1 || inRightCnt == 1) && (root->val == p->val || root->val == q->val)) {
      std::cout << "found node in one side: "<< root->val <<std::endl;
      same_parent = root;
    }

    // 返回值的判断：两个节点与当前节点匹配，则返回存在1个节点；否则返回0个节点
    int cnt = 0;
    if ((inLeftCnt == 1 || inRightCnt == 1) || (root->val == p->val || root->val == q->val)) {
      cnt = 1;
    }

    std::cout << "travel: " << root->val << ", exist cnt: " << cnt<< ", leftCnt:" << inLeftCnt << ", rightCnt:" << inRightCnt << ", root: " << root->val << std::endl;

    return cnt;
  }
};

// g++ same_parent.cpp -std=c++11
int main() {
  std::vector<int> array = {3,5,1,6,2,0,8,-1,-1,7,4};
  TreeNode* root = ConstructTree(array);
  TreeNode* p = new TreeNode(5);
  TreeNode* q = new TreeNode(1);
  Solution s;
  TreeNode* res = s.lowestCommonAncestor(root, p, q);
  if (res != nullptr)
  {
    std::cout << "[ok] exist res: " << res->val << std::endl;
  } else {
    std::cerr << "[err] not found same parent" << std::endl;
  }
  
  return 0;
}
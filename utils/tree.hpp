#include <list>
#include <vector>

namespace utils {
    
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *ConstructTree(std::vector<int> array) {
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
        currNode = nodeQueue.front();nodeQueue.pop_front();
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
}

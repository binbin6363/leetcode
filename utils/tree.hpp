#include <list>
#include <vector>
#include <math.h>

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


void PrintNodeInternal(std::vector<TreeNode*> nodes, int level, int maxLevel) {
        if (nodes.empty() || isAllElementsNull(nodes)) {
            return;
        }

        int floor = maxLevel - level;
        int endgeLines = (int) pow(2, (std::max(floor - 1, 0)));
        int firstSpaces = (int) pow(2, (floor)) - 1;
        int betweenSpaces = (int) pow(2, (floor + 1)) - 1;

        printWhitespaces(firstSpaces);

        std::vector<TreeNode*> newNodes;
        for (int i = 0; i <nodes.size();i++) {
            TreeNode *node = nodes[i];
            if (node != nullptr) {
                std::cout << (node->val);
                newNodes.push_back(node->left);
                newNodes.push_back(node->right);
            } else {
                newNodes.push_back(nullptr);
                newNodes.push_back(nullptr);
                std::cout << " ";
            }

            printWhitespaces(betweenSpaces);
        }
        std::cout << std::endl;

        for (int i = 1; i <= endgeLines; i++) {
            for (int j = 0; j < nodes.size(); j++) {
                printWhitespaces(firstSpaces - i);
                if (nodes[j] == nullptr) {
                    printWhitespaces(endgeLines + endgeLines + i + 1);
                    continue;
                }

                if (nodes[j]->left != nullptr) {
                    std::cout << "/";
                } else {
                    printWhitespaces(1);
                }

                printWhitespaces(i + i - 1);
                if (nodes[j]->right != nullptr) {
                    std::cout << "\\";
                } else {
                    printWhitespaces(1);
                }
                printWhitespaces(endgeLines + endgeLines - i);
            }

            std::cout << std::endl;
        }

        PrintNodeInternal(newNodes, level + 1, maxLevel);
    }

    void printWhitespaces(int count) {
        for (int i = 0; i < count; i++) {
            std::cout << " ";
        }
    }

    bool isAllElementsNull(std::vector<TreeNode*> vec) {
        for (TreeNode *t : vec) {
            if (t != nullptr) {
                return false;
            }
        }

        return true;
    }
}

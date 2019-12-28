//
// Created by Xiangwei Niu on 12/25/19.
//
#include "binaryTree.h"
#include <vector>
#include <stack>

#ifndef ALLTREE_104_H
#define ALLTREE_104_H
using namespace std;

class Solution104 {
public:
    int p104_maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int maxDepth = 0;
        int curDepth = 1;
        maxDepthHelper(root, maxDepth, curDepth);
        return maxDepth;
    }

    // bottom-up
    int maxDepth(TreeNode* root)
    {
        return getAnswer(root, 0);
    }

private:
    void maxDepthHelper(TreeNode* root, int &maxDepth, int curDepth){
        if (root->left == nullptr && root->right == nullptr){
            if (curDepth > maxDepth)
                maxDepth = curDepth;
            return;
        }
        if (root->left != nullptr){
            maxDepthHelper(root->left, maxDepth, curDepth+1);
        }
        if (root->right != nullptr){
            maxDepthHelper(root->right, maxDepth, curDepth+1);
        }
    }

    int getAnswer(TreeNode* node, int parentDepth)
    {
        if (node == nullptr)
            return parentDepth;

        int leftA = getAnswer(node->left, parentDepth + 1);
        int rightA = getAnswer(node->right, parentDepth + 1);
        return max(leftA, rightA);
    }
};
#endif //ALLTREE_104_H

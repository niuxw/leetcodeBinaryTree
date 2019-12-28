//
// Created by Xiangwei Niu on 12/25/19.
//
#include "binaryTree.h"
#include <vector>
#include <stack>

#ifndef ALLTREE_111_H
#define ALLTREE_111_H
using namespace std;

class Solution111 {
public:
    int p111_minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int minDepth = INT_MAX;
        int curDepth = 1;
        minDepthHelper(root, minDepth, curDepth);
        return minDepth;
    }

private:
    void minDepthHelper(TreeNode* root, int &minDepth, int curDepth){
        if (root->left == nullptr && root->right == nullptr){
            if (curDepth < minDepth)
                minDepth = curDepth;
            return;
        }
        if (root->left != nullptr){
            minDepthHelper(root->left, minDepth, curDepth+1);
        }
        if (root->right != nullptr){
            minDepthHelper(root->right, minDepth, curDepth+1);
        }
    }
};
#endif //ALLTREE_111_H

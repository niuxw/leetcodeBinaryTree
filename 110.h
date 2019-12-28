//
// Created by Xiangwei Niu on 12/25/19.
//
#include "binaryTree.h"
#include <vector>
#include <stack>

#ifndef ALLTREE_110_H
#define ALLTREE_110_H
using namespace std;
class Solution110 {
public:
    bool p110_isBalanced(TreeNode* root) {
        if (root == nullptr)
            return false;
        bool isBalanced = true;
        isBalancedHelper(root, 0, isBalanced);
        return isBalanced;
    }

private:
    int isBalancedHelper(TreeNode* root, int depth, bool &isBalanced){
        if (root == nullptr){
            return depth;
        }

        int leftHeight = isBalancedHelper(root->left, depth + 1, isBalanced);
        int rightHeight = isBalancedHelper(root->right, depth + 1, isBalanced);
        if (isBalanced) {
            if (abs(leftHeight - rightHeight) <= 1) {
                isBalanced = true;
            } else
                isBalanced = false;
        }
        return max(leftHeight,rightHeight);
    }
};
#endif //ALLTREE_110_H

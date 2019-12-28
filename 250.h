//
// Created by Xiangwei Niu on 12/26/19.
//
#include "binaryTree.h"
#include <vector>
#include <stack>

//https://www.lintcode.com/problem/count-univalue-subtrees/

#ifndef ALLTREE_250_H
#define ALLTREE_250_H
using namespace std;

class Solution250 {
public:
    int p250_countUnivalSubtrees(TreeNode * root) {
        if (root == nullptr)
            return false;
        count = 0;
        countUnivalSubtreesHelper(root);
        return count;
    }

private:
    int count;
    bool countUnivalSubtreesHelper(TreeNode* root){
        if (root->left == nullptr && root->right == nullptr){
            ++count;
            return true;
        }

        bool isUniVal = true;
        if (root->left != nullptr){
            isUniVal = countUnivalSubtreesHelper(root->left) && isUniVal && root->val == root->left->val;
        }
        if (root->right != nullptr){
            isUniVal = countUnivalSubtreesHelper(root->right) && isUniVal && root->val == root->right->val;
        }
        if (!isUniVal)
            return false;
        ++count;
        return true;
    }
};
#endif //ALLTREE_250_H

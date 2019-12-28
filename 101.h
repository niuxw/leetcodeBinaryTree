//
// Created by Xiangwei Niu on 12/12/19.
//
#include "binaryTree.h"
#include <vector>
#include <stack>

#ifndef ALLTREE_101_H
#define ALLTREE_101_H
class Solution101 {
public:
    bool p101_isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return isSymmetricHelper(root->left,root->right);
    }

//    bool p101_isSymmetric(TreeNode* root) {
//        if (root == nullptr)
//            return true;
//        return isSymmetricHelper(root->left,root->right);
//    }
private:
    bool isSymmetricHelper(TreeNode* left, TreeNode* right){
        if (left!= nullptr && right != nullptr && left->val == right->val){
            return isSymmetricHelper(left->left,right->right) && isSymmetricHelper(left->right,right->left);
        }
        else if (left == nullptr && right == nullptr){
            return true;
        }
        else{
            return false;
        }
    }
};
#endif //ALLTREE_101_H

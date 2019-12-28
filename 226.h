//
// Created by Xiangwei Niu on 12/12/19.
//
#include "binaryTree.h"
#include <vector>
#include <stack>

#ifndef ALLTREE_226_H
#define ALLTREE_226_H
class Solution226 {
public:
    TreeNode* p226_invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        TreeNode* newRoot = nullptr;
        invertTreeHelper(root, newRoot);
        return newRoot;
    }

    //preorder
    TreeNode* p226_invertTreeIter(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()){
            TreeNode* curNode = s.top();
            s.pop();
            TreeNode* temp = curNode->left;
            curNode->left = curNode->right;
            curNode->right = temp;

            if (curNode->right != nullptr){
                s.push(curNode->right);
            }
            if (curNode->left != nullptr){
                s.push(curNode->left);
            }

        }
        return root;
    }
private:
    // TODO need improve
    void invertTreeHelper(TreeNode* root, TreeNode* &newRoot){
        newRoot = new TreeNode(root->val);
        if (root->left != nullptr){
            invertTreeHelper(root->left, newRoot->right);
        }
        if (root->right != nullptr){
            invertTreeHelper(root->right, newRoot->left);
        }
    }

};
#endif //ALLTREE_226_H

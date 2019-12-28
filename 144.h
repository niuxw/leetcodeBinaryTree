//
// Created by niuxw on 12/10/2019.
//
#include "binaryTree.h"
#include <vector>
#include <stack>

#ifndef UNTITLED2_144_H
#define UNTITLED2_144_H
//144. Binary Tree Preorder Traversal

using namespace std;
class Solution144 {
public:
    vector<int> p144_preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorderHelper(root, result);
        return result;
    }

    vector<int> p144_preorderTraversalIter(TreeNode* root) {
        vector<int> result;
        if (root == nullptr)
            return result;
        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()){
            TreeNode* curNode = s.top();
            result.push_back(curNode->val);
            s.pop();

            if (curNode->right != nullptr){
                s.push(curNode->right);
            }
            if (curNode->left != nullptr){
                s.push(curNode->left);
            }
        }
        return result;
    }
private:
    //recursion
    void preorderHelper(TreeNode* root, vector<int> &r){
        if (root == nullptr){
            return;
        }
        r.push_back(root->val);
        preorderHelper(root->left, r);
        preorderHelper(root->right, r);
    }
    //iterative

};
#endif //UNTITLED2_144_H

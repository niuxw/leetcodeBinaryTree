//
// Created by Xiangwei Niu on 12/10/19.
//
#include "binaryTree.h"
#include <vector>
#include <stack>

#ifndef UNTITLED2_94_H
#define UNTITLED2_94_H
using namespace std;
// inorder: left root right
class Solution94 {
public:
    vector<int> p94_inorderTraversal(TreeNode* root) {
        vector<int> r;
        inorderHelper(root,r);
        return r;
    }
    vector<int> p94_inorderTraversalIter(TreeNode* root) {
        vector<int> r;
        stack<TreeNode*> s;
        //s.push(root);
        TreeNode* curNode = root;
        while (curNode != nullptr || !s.empty()){

            while (curNode != nullptr){
                s.push(curNode);
                curNode = curNode->left;
            }
            curNode = s.top();
            r.push_back(curNode->val);
            s.pop();
            curNode = curNode->right;

        }

        return r;
    }

private:
    //recursion
    void inorderHelper(TreeNode* root, vector<int> &r){
        if (root == nullptr){
            return;
        }
        inorderHelper(root->left,r);
        r.push_back(root->val);
        inorderHelper(root->right,r);
    }
};
#endif //UNTITLED2_94_H

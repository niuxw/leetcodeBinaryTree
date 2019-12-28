//
// Created by Xiangwei Niu on 12/23/19.
//
#include "binaryTree.h"
#include <vector>
#include <stack>

#ifndef ALLTREE_257_H
#define ALLTREE_257_H
using namespace std;
class Solution257 {
public:
    vector<string> p257_binaryTreePaths(TreeNode* root) {
        vector<string> r;
        if (root == nullptr){
            return r;
        }
        string s = to_string(root->val);
        binaryTreePathsHelper(root, r,s);
        return r;
    }

    vector<string> p257_binaryTreePathsIter(TreeNode* root) {
        vector<string> r;
        if (root == nullptr){
            return r;
        }
        stack<TreeNode*> s;
        stack<string> strs;
        s.push(root);
        string str = to_string(root->val);
        strs.push(str);
        while (!s.empty()){
            TreeNode* curNode = s.top();
            s.pop();
            str = strs.top();
            strs.pop();

            if (curNode->left == nullptr && curNode->right == nullptr){
                r.push_back(str);
            } else{
                if (curNode->left != nullptr){
                    s.push(curNode->left);
                    string curStr = str + "->" + to_string(curNode->left->val);
                    strs.push(curStr);
                }
                if (curNode->right != nullptr){
                    s.push(curNode->right);
                    string curStr = str + "->" + to_string(curNode->right->val);
                    strs.push(curStr);
                }
            }
        }
        return r;
    }

private:
    void binaryTreePathsHelper(TreeNode* root, vector<string> &r, string &s){
        if (root->left == nullptr && root->right == nullptr){
            r.push_back(s);
        }
        else {
            if (root->left != nullptr) {
                s += "->" + to_string(root->left->val);
                binaryTreePathsHelper(root->left, r, s);
                size_t pos = s.find_last_of(">");
                s.erase(pos-1);
            }
            if (root->right != nullptr) {
                s += "->" + to_string(root->right->val);
                binaryTreePathsHelper(root->right, r, s);
                size_t pos = s.find_last_of(">");
                s.erase(pos-1);
            }
        }
    }

};
#endif //ALLTREE_257_H

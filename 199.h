//
// Created by Xiangwei Niu on 12/29/19.
//
#include "binaryTree.h"
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

#ifndef ALLTREE_199_H
#define ALLTREE_199_H
class Solution199 {
public:
    vector<int> p199_rightSideView(TreeNode* root) {
        vector<int> r;
        if (root == nullptr)
            return r;
        //r.push_back(root->val);
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            int breadth = q.size();
            TreeNode* curNode;
            for (int i = 0; i < breadth; ++i){
                curNode = q.front();
                q.pop();

                if (curNode->left != nullptr){
                    q.push(curNode->left);
                }
                if (curNode->right != nullptr){
                    q.push(curNode->right);
                }
            }
            r.push_back(curNode->val);
        }
        return r;
    }

private:
//    void rightSideViewHelper(TreeNode* root, vector<int> &r, bool &finished){
//        if (root->left == nullptr && root->right == nullptr){
//            finished = true;
//            return;
//        }
//        if (root->right != nullptr && !finished) {
//            r.push_back(root->right->val);
//            rightSideViewHelper(root->right, r, finished);
//        }
//        if (root->left != nullptr && !finished) {
//            r.push_back(root->left->val);
//            rightSideViewHelper(root->left, r, finished);
//        }
//
//    }
};
#endif //ALLTREE_199_H

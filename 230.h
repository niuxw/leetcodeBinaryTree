//
// Created by Xiangwei Niu on 1/8/20.
//
#include "binaryTree.h"
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

#ifndef ALLTREE_230_H
#define ALLTREE_230_H
class Solution230 {
public:
    int p230_kthSmallestIter(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* curNode = root;
        while (curNode != nullptr || !s.empty()){
            while (curNode != nullptr){
                s.push(curNode);
                curNode = curNode->left;
            }

            curNode = s.top();
            s.pop();
            --k;
            if (k == 0){
                return curNode->val;
            }

            curNode = curNode->right;
        }
        return -1;
    }

    int p230_kthSmallest(TreeNode* root, int k) {
        int val = 0;
        kthSmallest(root,k,val);
        return val;
    }

private:
    void kthSmallest(TreeNode* root, int& k, int& val){
        if (root == nullptr)
            return;
        kthSmallest(root->left, k, val);
        --k;
        if (k == 0){
            val = root->val;
            return;
        }
        kthSmallest(root->right, k, val);
    }
};
#endif //ALLTREE_230_H

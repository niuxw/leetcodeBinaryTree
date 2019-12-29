//
// Created by Xiangwei Niu on 12/28/19.
//
//https://www.lintcode.com/problem/binary-tree-longest-consecutive-sequence/description

#include "binaryTree.h"
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

#ifndef ALLTREE_298_H
#define ALLTREE_298_H
class Solution298 {
public:
    int p298_longestConsecutive(TreeNode * root) {
        maxLength = 0;
        if (root ==nullptr)
            return 0;
        longestConsecutiveHelper(root, 1);
        return maxLength;
        // write your code here
//        stack<TreeNode*> s;
//        s.push(root);
//        while (!s.empty()){
//            TreeNode* curNode = s.top();
//            s.pop();
//            if (curNode->right != nullptr){
//                s.push(curNode->right);
//            }
//            if (curNode->left != nullptr){
//                s.push(curNode->left);
//            }

    }

private:
    int maxLength;
    void longestConsecutiveHelper(TreeNode * root, int len){
        if (root->left == nullptr && root->right == nullptr){
            if (len > maxLength)
                maxLength = len;
            return;
        }

        if (root->left != nullptr){
            if (root->left->val == root->val + 1)
                longestConsecutiveHelper(root->left, len+1);
            else {
                if (len > maxLength)
                    maxLength = len;

                longestConsecutiveHelper(root->left, 1);
            }
        }
        if (root->right != nullptr){
            if (root->right->val == root->val + 1)
                longestConsecutiveHelper(root->right, len+1);
            else {
                if (len > maxLength)
                    maxLength = len;

                longestConsecutiveHelper(root->right, 1);
            }
        }
    }
};
#endif //ALLTREE_298_H

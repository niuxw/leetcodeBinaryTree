//
// Created by Xiangwei Niu on 12/25/19.
//
#include "binaryTree.h"
#include <vector>
#include <stack>

#ifndef ALLTREE_129_H
#define ALLTREE_129_H
using namespace std;
class Solution129 {
public:
    int p129_sumNumbers(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int sum = 0;
        int number = root->val;
        sumNumbers(root, sum, number);
        return sum;
    }

private:
    void sumNumbers(TreeNode* root, int &sum, int number){
        if (root->left == nullptr && root->right == nullptr){
            sum += number;
            return;
        }
        if (root->left != nullptr){
            int curNumber = number*10 + root->left->val;
            sumNumbers(root->left, sum, curNumber);
        }
        if (root->right != nullptr){
            int curNumber = number*10 + root->right->val;
            sumNumbers(root->right, sum, curNumber);
        }
    }
};
#endif //ALLTREE_129_H

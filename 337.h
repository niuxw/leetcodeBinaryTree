//
// Created by Xiangwei Niu on 12/27/19.
//
// reference:
//https://www.cnblogs.com/grandyang/p/5275096.html

#include "binaryTree.h"
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

#ifndef ALLTREE_337_H
#define ALLTREE_337_H
class Solution337 {
public:
    int p337_rob(TreeNode* root) {
        if (root == nullptr)
            return 0;
        unordered_map<TreeNode*, int> m;
        return robHelper(root, m);
    }

private:
    int robHelper(TreeNode* root, unordered_map<TreeNode*, int> &m){
        if (root == nullptr)
            return 0;
        if (m.count(root))
            return m[root];
        int leftV = 0;
        int rightV = 0;
        if (root->left != nullptr){
            leftV = robHelper(root->left->left, m) + robHelper(root->left->right, m);
        }
        if (root->right != nullptr){
            rightV = robHelper(root->right->left, m) + robHelper(root->right->right, m);
        }
        int childrenVal = robHelper(root->left, m) + robHelper(root->right, m);
        int curAndGrandchild = root->val + leftV + rightV;
        int curVal = max(childrenVal,curAndGrandchild);
        m[root] = curVal;
        return curVal;
    }
};
#endif //ALLTREE_337_H

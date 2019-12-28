//
// Created by Xiangwei Niu on 12/25/19.
//
#include "binaryTree.h"
#include <vector>
#include <stack>

#ifndef ALLTREE_113_H
#define ALLTREE_113_H
using namespace std;
class Solution113 {
public:
    vector<vector<int>> p113_pathSum(TreeNode* root, int sum) {
        vector<vector<int>> r;
        if (root == nullptr)
            return r;
        vector<int> cr;
        cr.push_back(root->val);
        int s = root->val;
        pathSumHelper(root, r, cr, s, sum);
        return r;
    }

private:
    void pathSumHelper(TreeNode* root, vector<vector<int>> &r, vector<int> &cr, int s, int sum){
        if (root->left == nullptr && root->right == nullptr){
            if (s == sum)
                r.push_back(cr);
            return;
        }
        if (root->left != nullptr){
            int curS = s + root->left->val;
            cr.push_back(root->left->val);
            pathSumHelper(root->left,r,cr,curS,sum);
            cr.pop_back();
        }
        if (root->right != nullptr ){
            int curS = s + root->right->val;
            cr.push_back(root->right->val);
            pathSumHelper(root->right,r,cr,curS,sum);
            cr.pop_back();
        }
    }
};
#endif //ALLTREE_113_H

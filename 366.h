//
// Created by Xiangwei Niu on 12/27/19.
//

//https://www.lintcode.com/problem/find-leaves-of-binary-tree/description

//The depth of a node is the number of edges from the root to the node.
//The height of a node is the number of edges from the node to the deepest leaf.
//The height of a tree is a height of the root.
//A full binary tree.is a binary tree in which each node has exactly zero or two children.
//A complete binary tree is a binary tree, which is completely filled, with the possible exception of the bottom level, which is filled from left to right.

#include "binaryTree.h"
#include <vector>
#include <stack>
using namespace std;

#ifndef ALLTREE_366_H
#define ALLTREE_366_H

class Solution366 {
public:
    vector<vector<int>> p366_findLeaves(TreeNode * root) {
        // write your code here
        if (root == nullptr)
            return r;
        r.resize(1);
        findLeavesHelper(root);
        return r;
    }

private:
    vector<vector<int>> r;
    //get height for each node
    int findLeavesHelper(TreeNode* root){
        if (root->left == nullptr && root->right == nullptr){
            vector<int> &v = r[0];
            v.push_back(root->val);
            return 1;
        }
        int leftHeight = 0;
        int rightHeight = 0;
        if (root->left != nullptr){
            leftHeight = findLeavesHelper(root->left);
        }
        if (root->right != nullptr){
            rightHeight = findLeavesHelper(root->right);
        }
        int curHeight = max(leftHeight, rightHeight) + 1;
        if (r.size() < curHeight){
            r.push_back(vector<int> {root->val});
        }
        else{
            vector<int> &v = r[curHeight-1];
            v.push_back(root->val);
        }
        return curHeight;
    }
};
#endif //ALLTREE_366_H

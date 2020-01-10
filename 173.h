//
// Created by Xiangwei Niu on 1/8/20.
//
#include "binaryTree.h"
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

#ifndef ALLTREE_173_H
#define ALLTREE_173_H
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        inorder(root);
        i = 0;
    }
    void inorder(TreeNode* root){
        if (root == nullptr){
            return;
        }
        inorder(root->left);
        r.push_back(root->val);
        inorder(root->right);
    }
    /** @return the next smallest number */
    int next() {
        return r[i++];
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (i != r.size()-1);
    }

private:
    vector<int> r;
    int i;
};


#endif //ALLTREE_173_H

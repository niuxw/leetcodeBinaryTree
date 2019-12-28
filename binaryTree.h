//
// Created by niuxw on 12/10/2019.
//

#ifndef UNTITLED2_BINARYTREE_H
#define UNTITLED2_BINARYTREE_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {
    }
};
class binaryTree {
    TreeNode* root = nullptr;
    binaryTree(){

    }
    binaryTree(TreeNode* root){
        this->root = root;
    }
};


#endif //UNTITLED2_BINARYTREE_H

//
// Created by Xiangwei Niu on 12/29/19.
//
#include "binaryTree.h"
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

#ifndef ALLTREE_235_H
#define ALLTREE_235_H
class Solution235 {
public:
    TreeNode* p235_lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int minNode = min(p->val,q->val);
        int maxNode = max(p->val,q->val);
        TreeNode* curNode = root;
        while (curNode != nullptr){
            int curVal = curNode->val;
            if (curVal>maxNode)
                curNode = curNode->left;
            else if (curVal<minNode)
                curNode = curNode->right;
            else
                return curNode;
        }
        return nullptr;
    }
};
#endif //ALLTREE_235_H

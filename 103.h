//
// Created by Xiangwei Niu on 12/28/19.
//
#include "binaryTree.h"
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

#ifndef ALLTREE_103_H
#define ALLTREE_103_H
class Solution103 {
public:
    vector<vector<int>> p103_zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> r;
        if (root == nullptr)
            return r;
        queue<TreeNode*> q;
        q.push(root);
        bool reverse = false;
        while (!q.empty()){
            int breadth = q.size();
            vector<int > r1(breadth);
            for (int i =0; i< breadth ; ++i) {
                TreeNode *curNode = q.front();
                q.pop();
                if (reverse){
                    r1[breadth-i-1] = curNode->val;
                }
                else{
                    r1[i] = curNode->val;
                }
                if (curNode->left != nullptr) {
                    q.push(curNode->left);
                }
                if (curNode->right != nullptr) {
                    q.push(curNode->right);
                }

            }
            r.push_back(r1);
            reverse = !reverse;
        }
        return r;
    }
};
#endif //ALLTREE_103_H

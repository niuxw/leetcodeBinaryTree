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
        bool reverse = true;
        while (!q.empty()){
            int breadth = q.size();
            vector<int > r1(breadth);
            stack<TreeNode*> reverseQ;
            stack<pair<TreeNode*, TreeNode*>> normalQ;
            for (int i =0; i< breadth ; ++i) {
                TreeNode *curNode = q.front();
                q.pop();
                r1[i] = curNode->val;
                if (reverse){
                    if (curNode->left != nullptr) {
                        reverseQ.push(curNode->left);
                    }
                    if (curNode->right != nullptr) {
                        reverseQ.push(curNode->right);
                    }
                }
                else{
                    pair<TreeNode*, TreeNode*> tmp;
                    if (curNode->left != nullptr) {
                        //q.push(curNode->left);
                        tmp.first = curNode->left;
                    }
                    if (curNode->right != nullptr) {
                        //q.push(curNode->right);
                        tmp.second = curNode->right;
                    }
                    normalQ.push(tmp);
                }
            }
            r.push_back(r1);
            if (reverse){
                while (!reverseQ.empty()){
                    q.push(reverseQ.top());
                    reverseQ.pop();
                }
            }
            else{
                while (!normalQ.empty()){
                    TreeNode* ln = normalQ.top().first;
                    TreeNode* rn = normalQ.top().second;
                    if (ln != nullptr)
                        q.push(ln);
                    if (rn != nullptr)
                        q.push(rn);
                    normalQ.pop();
                }
            }
            reverse = !reverse;
        }
        return r;
    }
};
#endif //ALLTREE_103_H

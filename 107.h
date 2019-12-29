//
// Created by Xiangwei Niu on 12/28/19.
//
#include "binaryTree.h"
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

#ifndef ALLTREE_107_H
#define ALLTREE_107_H
class Solution107 {
public:
    //BFS
    vector<vector<int>> p107_levelOrderBottomIter(TreeNode* root) {
        vector<vector<int>> r;
        if (root == nullptr)
            return r;
        stack<vector<int>> r1;
        queue<TreeNode*> q;
        q.push(root);
        //int level = 0;
        while (!q.empty()){
            int breadth = q.size();
            vector<int> r2(breadth);
            for (int i = 0; i < breadth; ++i) {
                TreeNode *curNode = q.front();
                q.pop();
                r2[i] = curNode->val;
                if (curNode->left != nullptr) {
                    q.push(curNode->left);
                }
                if (curNode->right != nullptr) {
                    q.push(curNode->right);
                }
            }
            //r.insert(r.begin(),r2);
            r1.push(r2);
            //++level;
        }


        while (!r1.empty()){
            r.push_back(r1.top());
            r1.pop();
        }
        return r;
    }
};
#endif //ALLTREE_107_H

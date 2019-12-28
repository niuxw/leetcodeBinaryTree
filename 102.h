//
// Created by Xiangwei Niu on 12/12/19.
//
#include "binaryTree.h"
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
#ifndef ALLTREE_102_H
#define ALLTREE_102_H
class Solution102 {
public:
    vector<vector<int>> p102_levelOrder(TreeNode* root) {
        vector<vector<int>> r;
        if (root == nullptr){
            return r;
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<int> r1{root->val};
        r.push_back(r1);
        int curLevelNodeNum = 1;
        int nextLevelNodeNum = 2*curLevelNodeNum;
        vector<int> ri;
        while (!q.empty()){
            TreeNode* curNode = q.front();
            q.pop();
            --curLevelNodeNum;
            if (curNode->left != nullptr){
                q.push(curNode->left);
                ri.push_back(curNode->left->val);
            }
            else{
                --nextLevelNodeNum;
            }
            if (curNode->right != nullptr){
                q.push(curNode->right);
                ri.push_back(curNode->right->val);
            }
            else{
                --nextLevelNodeNum;
            }
            if (curLevelNodeNum == 0) {
                curLevelNodeNum = nextLevelNodeNum;
                nextLevelNodeNum = 2*curLevelNodeNum;
                if (ri.size() > 0)
                    r.push_back(ri);
                ri.clear();
            }
        }
        return r;
    }

    //better solution
    vector<vector<int>> p102_levelOrder2(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> vec;

        if(!root)
            return vec;

        q.push(root);

        int i = 0;
        while(!q.empty())
        {
            int breadth = q.size();
            vec.push_back(vector<int>(breadth));
            int j = 0;
            while(breadth--)
            {
                TreeNode *v = q.front();
                vec[i][j] = v->val;
                q.pop();

                if(v->left)
                    q.push(v->left);
                if(v->right)
                    q.push(v->right);
                j++;
            }
            i++;
        }
        return vec;
    }
};
#endif //ALLTREE_102_H

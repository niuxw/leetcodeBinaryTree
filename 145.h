//
// Created by Xiangwei Niu on 12/12/19.
//
#include "binaryTree.h"
#include <vector>
#include <stack>

using namespace std;
#ifndef ALLTREE_P145_H
#define ALLTREE_P145_H
// postOrder left right root
class Solution145 {
public:
    vector<int> p145_postorderTraversal(TreeNode* root) {
        vector<int> r;
        postOrderHelper(root,r);
        return r;
    }
    vector<int> p145_postorderTraversalIter(TreeNode* root) {
        vector<int> r;
        if (root == nullptr)
            return r;
        stack<pair<TreeNode*, int>> s;
        s.push({root,0});
        while (!s.empty()){
            auto curPair = s.top();
            s.pop();
            if (curPair.first == nullptr){
                continue;
            }
            if (curPair.second == 0){
                s.push({curPair.first, 1});
                s.push({curPair.first->right, 0});
                s.push({curPair.first->left, 0});
            }
            else{
                r.push_back(curPair.first->val);
            }
        }
        return r;
    }
private:
    void postOrderHelper(TreeNode* root, vector<int> &r){
        if (root == nullptr){
            return;
        }
        postOrderHelper(root->left,r);
        postOrderHelper(root->right,r);
        r.push_back(root->val);
    }
};
#endif //ALLTREE_P145_H

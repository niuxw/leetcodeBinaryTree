//
// Created by Xiangwei Niu on 12/30/19.
//
#include "binaryTree.h"
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

#ifndef ALLTREE_236_H
#define ALLTREE_236_H
class Solution236 {
public:
    //preorder
    TreeNode* p236_lowestCommonAncestorIter(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<vector<TreeNode*>> v;
        vector<TreeNode*> v2;
        stack<TreeNode*> s;
        s.push(root);
        int found = 0;
        while (!s.empty() && found < 2){
            TreeNode* curNode = s.top();
            s.pop();
            v2.push_back(curNode);
            if (curNode->val == p->val || curNode->val == q->val){
                v.push_back(v2);
            }

        }
        return nullptr;
    }

    TreeNode* p236_lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return nullptr;
        result = nullptr;
        find = false;
        lowestCommonAncestorHelper2(root, p->val, q->val);
        return result;
    }

    TreeNode* p236_lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<vector<TreeNode*>> v;
        vector<TreeNode*> v2;
        v2.push_back(root);
        int found = 0;
        lowestCommonAncestorHelper(root,p->val, q->val, v2, v, found);

        int i;
        for (i =0; i < min(v[0].size(), v[1].size()); ++i){
            TreeNode* t1 = v[0][i];
            TreeNode* t2 = v[1][i];

            if(t1->val != t2->val){
                return v[0][i-1];
            }
        }
        return (v[0].size()< v[1].size()) ? v[0][i-1] : v[1][i-1];
    }

private:
    TreeNode* result;
    bool find;
    int lowestCommonAncestorHelper2(TreeNode* root, int valP, int valQ) {
        if (root == nullptr || find)
            return false;
        int left = lowestCommonAncestorHelper2(root->left, valP, valQ);
        int right = lowestCommonAncestorHelper2(root->right, valP, valQ);
        int mid = (root->val == valP || root->val == valQ) ? 1:0;
        if (left + right + mid >= 2 && !find) {
            result = root;
            find = true;
        }
        return (left + right + mid > 0);
    }

    void lowestCommonAncestorHelper(TreeNode* root, int valP, int valQ, vector<TreeNode*> v2, vector<vector<TreeNode*>> &v, int &found) {
        if (root == nullptr){
            return;
        }
        if (root->val == valP || root->val == valQ){
            v.push_back(v2);
            ++found;
        }
        vector<TreeNode*> tmp1 = v2;
        tmp1.push_back(root->left);
        if (found >=2)
            return;
        lowestCommonAncestorHelper(root->left,valP,valQ,tmp1,v, found);
        tmp1 = v2;
        tmp1.push_back(root->right);
        if (found >=2)
            return;
        lowestCommonAncestorHelper(root->right,valP,valQ,tmp1,v, found);
    }

};
#endif //ALLTREE_236_H

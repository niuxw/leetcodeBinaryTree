//
// Created by Xiangwei Niu on 12/29/19.
//
#include "binaryTree.h"
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

#ifndef ALLTREE_98_H
#define ALLTREE_98_H
class Solution98 {
public:
    // print inorder and check if it is ascending order
    bool p98_isValidBSTIter(TreeNode* root) {
        if (root == nullptr)
            return true;
        //vector<int> r;
        stack<TreeNode*> s;
        TreeNode* curNode = root;
        bool first = true;
        int preVal = INT_MIN;

        while (curNode!= nullptr || !s.empty()){
            while (curNode != nullptr){
                s.push(curNode);
                curNode = curNode->left;
            }
            curNode = s.top();
            s.pop();
            //r.push_back(curNode->val);
            if (first){
                preVal = curNode->val;
                first = false;
            }else {
                if (curNode->val <= preVal)
                    return false;
                preVal = curNode->val;
            }
            curNode = curNode->right;
        }
        return true;
    }
    bool p98_isValidBST(TreeNode* root) {
//        if (root == nullptr)
//            return true;
        return isValidBSTHelper(root, nullptr, nullptr);
    }

private:
    bool isValidBSTHelper(TreeNode* root, int* maxVal, int* minVal){
        if (root == nullptr)
            return true;
        if (maxVal != nullptr) {
            if (root->val >= *maxVal)
                return false;
        }
        if (minVal != nullptr){
            if (root->val <= *minVal)
                return false;
        }
        return isValidBSTHelper(root->left, &root->val, minVal)
                && isValidBSTHelper(root->right, maxVal, &root->val);
    }

};
#endif //ALLTREE_98_H

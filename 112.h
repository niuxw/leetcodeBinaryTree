//
// Created by Xiangwei Niu on 12/24/19.
//
#include "binaryTree.h"
#include <vector>
#include <stack>

#ifndef ALLTREE_112_H
#define ALLTREE_112_H

using namespace std;
class Solution112 {
public:
    bool p112_hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr)
            return false;
        int s = root->val;
        return hasPathSumHelper(root, s, sum);
    }

    bool p112_hasPathSumIter(TreeNode* root, int sum) {
        if (root == nullptr)
            return false;
        stack<TreeNode*> s;
        stack<int> sumS;
        s.push(root);
        sumS.push(root->val);
        while(!s.empty()){
            TreeNode* curNode = s.top();
            s.pop();
            int curSum = sumS.top();
            sumS.pop();
            if (curNode->left == nullptr && curNode->right == nullptr){
                if (curSum == sum)
                    return true;
            }
            else{
                if (curNode->right != nullptr){
                    s.push(curNode->right);
                    sumS.push(curSum + curNode->right->val);
                }
                if (curNode->left != nullptr){
                    s.push(curNode->left);
                    sumS.push(curSum + curNode->left->val);
                }
            }
        }
        return false;
    }

private:
    bool hasPathSumHelper(TreeNode* root, int s, int sum) {
        if (root->left == nullptr && root->right == nullptr){
            if (s == sum)
                return true;
            return false;
        }
        bool a = false;
        if (root->left != nullptr){
            int curS = s + root->left->val;
            if(hasPathSumHelper(root->left,curS,sum))
                a = true;
        }
        if (root->right != nullptr ){
            int curS = s + root->right->val;
            if ( hasPathSumHelper(root->right,curS,sum))
                a = true;
            //s -= root->right->val;
        }
        if (a)
            return true;
        return false;
    }
};
#endif //ALLTREE_112_H

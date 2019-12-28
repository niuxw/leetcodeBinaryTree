//
// Created by Xiangwei Niu on 12/12/19.
//
#include "binaryTree.h"
#include <vector>
#include <stack>

#ifndef ALLTREE_100_H
#define ALLTREE_100_H
class Solution100 {
public:
    bool p100_isSameTree(TreeNode* p, TreeNode* q) {
        return sameTreeHelper(p,q);
    }

    // preorder iter
    bool p100_isSameTreeIter(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr){
            return true;
        }
        else if (p == nullptr || q == nullptr){
            return false;
        }
        stack<TreeNode*> sp;
        stack<TreeNode*> sq;
        sp.push(p);
        sq.push(q);
        while (!sp.empty() && !sq.empty()){
            TreeNode* curP = sp.top();
            TreeNode* curQ = sq.top();
            if (curP->val != curQ->val){
                return false;
            }
            sp.pop();
            sq.pop();
            if (curP->right != nullptr && curQ->right != nullptr){
                sp.push(curP->right);
                sq.push(curQ->right);
            }
            else if (curP->right != nullptr || curQ->right != nullptr){
                return false;
            }
            if (curP->left != nullptr && curQ->left != nullptr){
                sp.push(curP->left);
                sq.push(curQ->left);
            }
            else if(curP->left != nullptr || curQ->left != nullptr){
                return false;
            }
        }
        if (!sp.empty() || !sq.empty()){
            return false;
        }
        return true;
    }

    // better
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
            return true;
        else if(p==NULL && q!=NULL){
            return false;
        } else if(p!=NULL && q==NULL)
            return false;
        else{
            return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
private:
    //preorder
    bool sameTreeHelper(TreeNode* p, TreeNode* q){
        if (p== nullptr && q == nullptr){
            return true;
        }
        else if (p== nullptr || q == nullptr){
            return false;
        } else if (p->val != q->val){
            return false;
        }
        return sameTreeHelper(p->left,q->left) && sameTreeHelper(p->right,q->right);
    }
};
#endif //ALLTREE_100_H

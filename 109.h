//
// Created by Xiangwei Niu on 1/2/20.
//
#include "binaryTree.h"
#include "ListNode.h"
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

#ifndef ALLTREE_109_H
#define ALLTREE_109_H
class Solution109 {
public:
    //slow fast pointer
    TreeNode* p109_sortedListToBST1(ListNode* head) {
        TreeNode* root = nullptr;
        sortedListToBST1(head, root);
        return root;
    }

    // convert to vector

private:
    ListNode* getMidNode(ListNode* beginNode){
        ListNode* slowNode = beginNode;
        ListNode* fastNode = beginNode;
        ListNode* slowPreNode = nullptr;

        while (fastNode->next != nullptr && fastNode->next->next != nullptr){
            slowPreNode = slowNode;
            slowNode = slowNode->next;

            fastNode = fastNode->next;
            fastNode = fastNode->next;
        }

        if (slowPreNode != nullptr){
            slowPreNode->next = nullptr;
        }
        return slowNode;
    }

    void sortedListToBST1(ListNode* beginNode, TreeNode* &root){
        if (beginNode == nullptr)
            return;
        ListNode* midNode = getMidNode(beginNode);
        root = new TreeNode(midNode->val);
        if (midNode != beginNode)
            sortedListToBST1(beginNode, root->left);
        sortedListToBST1(midNode->next, root->right);
    }
};

#endif //ALLTREE_109_H

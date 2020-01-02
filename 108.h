//
// Created by Xiangwei Niu on 1/1/20.
//
#include "binaryTree.h"
#include "ListNode.h"
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

#ifndef ALLTREE_108_H
#define ALLTREE_108_H
class Solution108 {
public:
    TreeNode* p108_sortedArrayToBST(vector<int>& nums) {
        if (nums.size()<1){
            return nullptr;
        }
        TreeNode* root = nullptr;
        sortedArrayToBSTHelper(nums, root, 0, nums.size()-1);
        return root;
    }

private:
    void sortedArrayToBSTHelper(vector<int>& nums, TreeNode* &root, int begin, int end){
        if (end < begin)
            return;
        if (end == begin)
        {
            root = new TreeNode(nums[end]);
            return;
        }
        int mid = (begin + end)/2;
        int curVal = nums[mid];
        root = new TreeNode(curVal);
        sortedArrayToBSTHelper(nums, root->left, begin,mid-1);
        sortedArrayToBSTHelper(nums, root->right, mid+1,end);
    }
};
#endif //ALLTREE_108_H

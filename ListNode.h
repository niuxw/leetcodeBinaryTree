//
// Created by Xiangwei Niu on 1/2/20.
//

#ifndef ALLTREE_LISTNODE_H
#define ALLTREE_LISTNODE_H
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#endif //ALLTREE_LISTNODE_H

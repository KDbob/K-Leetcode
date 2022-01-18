//
// Created by bob on 2021/11/16.
//

#ifndef K_LEETCODE_KSTRUCT_H
#define K_LEETCODE_KSTRUCT_H

typedef struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}

}ListNode;




#endif //K_LEETCODE_KSTRUCT_H

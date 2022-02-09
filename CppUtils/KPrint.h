//
// Created by bob on 2021/9/12.
//

#ifndef K_LEETCODE_KPRINT_H
#define K_LEETCODE_KPRINT_H

#include "KStruct.h"
/**
 * 打印链表
 * @param head 链表的头指针
 */
void printLinkedList(ListNode *head) {
    while (head) {
        printf("->%d", head->val);
        head = head->next;
    }
    printf("\n");
}

#endif //K_LEETCODE_KPRINT_H

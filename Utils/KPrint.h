//
// Created by bob on 2021/9/12.
//

#ifndef K_LEETCODE_KPRINT_H
#define K_LEETCODE_KPRINT_H


typedef struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}

}ListNode;

/**
 * 打印链表
 * @param head 链表的头指针
 */
void printLinkedList(ListNode *head) {
    while (head) {
        printf("->%d", head->val);
        head = head->next;
    }
}

/*
 * 打印一维数组
 */
void printArray(const vector<int>& arr) {
    for (auto n:arr) {
        printf("%d ", n);
    }
    printf("\n");
}

#endif //K_LEETCODE_KPRINT_H

// 21. 合并两个有序链表
// Created by kaide on 2021/5/4.
// Update by kaide on 2021/7/4

#include <iostream>
#include "KStruct.h"

using namespace std;


/**
 * 将两个升序链表合并为一个新的 升序 链表并返回
 * 《方法一：递归构建》
 * @param l1 升序链表l1
 * @param l2 升序链表l2
 * @return 合并后的链表
 */
ListNode *mergeTwoLists1(ListNode *l1, ListNode *l2) {
    if (!l1 || !l2) {
        if  (!l1) {
            return l2;
        } else {
            return l1;
        }
    }
    if (l1->val < l2->val) {
        l1->next = mergeTwoLists1(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists1(l1, l2->next);
        return l2;
    }
}

/**
 * 将两个升序链表合并为一个新的 升序 链表并返回
 * 《方法二：迭代法》
 * @param l1 升序链表l1
 * @param l2 升序链表l2
 * @return 合并后的链表
 */
ListNode *mergeTwoList2(ListNode *l1, ListNode *l2) {
    ListNode *prehead = new ListNode(-1);
    ListNode *prev = prehead;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            prev->next = l1;
            l1 = l1->next;
        } else {
            prev->next = l2;
            l2 = l2->next;
        }
        prev = prev->next;
    }
    prev->next = l1 ? l1 : l2;
    return prehead;
}

void test(ListNode *merge) {
    while (merge) {
        printf("->%d", merge->val);
        merge = merge->next;
    }
    printf("\n");
}

int main() {
    ListNode *head1 = new ListNode(1, new ListNode(2, new ListNode(4)));    // ->1->2->4
    ListNode *head2 = new ListNode(1, new ListNode(3, new ListNode(4)));    // ->1->3->4
    ListNode *merge1 = mergeTwoLists1(head1, head2); // 方法一：递归构建
    test(merge1);    // expect: 1->1->2->3->4->4

    ListNode *head3 = new ListNode(1, new ListNode(2, new ListNode(4)));    // ->1->2->4
    ListNode *head4 = new ListNode(1, new ListNode(3, new ListNode(4)));    // ->1->3->4
    ListNode *merge2 = mergeTwoList2(head3, head4);
    test(merge2);    // expect: 1->1->2->3->4->4
}
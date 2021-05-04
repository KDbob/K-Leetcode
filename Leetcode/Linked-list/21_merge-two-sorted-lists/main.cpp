// 21. 合并两个有序链表
// Created by kaide on 2021/5/4.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}

    ListNode(int x, ListNode *next) : val (x), next(next) {}
};

/**
 * 将两个升序链表合并为一个新的 升序 链表并返回
 * @param l1 升序链表l1
 * @param l2 升序链表l2
 * @return 合并后的链表
 */
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (!l1 || !l2) {
        if  (!l1) {
            return l2;
        } else {
            return l1;
        }
    }
    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

int main() {
    ListNode *head1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode *head2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode *merge = mergeTwoLists(head1, head2);
    while (merge) {
        printf("->%d", merge->val);     // expect: 1->1->2->3->4->4
        merge = merge->next;
    }

}
// 剑指 Offer 24. 反转链表
// Created by kaide on 2021/5/3.
//

#include <iostream>
#include "KPrint.h"

using namespace std;

/*  defined in KPrint.h
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}

};
*/

/**
 * 输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
 * 《方法一：迭代法》
 * @param head 链表的头节点
 * @return 反转后的链表的头节点
 */
ListNode *reverseList(ListNode *head) {
    ListNode *pre = nullptr;
    ListNode *curr = head;
    while (curr) {
        ListNode *next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }
    return pre;
}

int main() {
    // create linked list 1->2->3->4->5
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode *res = reverseList(head);
    printLinkedList(res);   // expect: ->5->4->3->2->1
//    printK(123);

}
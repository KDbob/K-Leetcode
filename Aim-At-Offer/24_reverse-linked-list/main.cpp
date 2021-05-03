// 剑指 Offer 24. 反转链表
// Created by kaide on 2021/5/3.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}

};

/**
 * 输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
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
    ListNode *node5 = new ListNode(5);
    ListNode *node4 = new ListNode(4, node5);
    ListNode *node3 = new ListNode(3, node4);
    ListNode *node2 = new ListNode(2, node3);
    ListNode *head = new ListNode(1, node2);
    ListNode *res = reverseList(head);
    while (res) {
        printf("->%d", res->val);   // expect: ->5->4->3->2->1
        res = res->next;
    }

}
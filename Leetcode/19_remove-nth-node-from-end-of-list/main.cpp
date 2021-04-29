// 19. 删除链表的倒数第 N 个结点
// Created by kaide on 2021/4/29.
//
#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * 删除链表的倒数第 n 个结点，并且返回链表的头结点
 * 《使用栈的思想》
 * @param head 头节点指针
 * @param n 倒数第n个节点
 * @return 删除第n个节点后的链表头结点
 */
ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *dummy = new ListNode(0, head);
    stack<ListNode *> stk;
    ListNode *cur = dummy;
    while (cur) {
        stk.push(cur);
        cur = cur->next;
    }
    while (n) {
        stk.pop();
        n--;
    }
    ListNode *top = stk.top();
    top->next = top->next->next;
    ListNode *res = dummy->next;
    delete dummy;
    return res;
}

int main() {
    ListNode *node5 = new ListNode(5);
    ListNode *node4 = new ListNode(4, node5);
    ListNode *node3 = new ListNode(3, node4);
    ListNode *node2 = new ListNode(2, node3);
    ListNode *head = new ListNode(1, node2);
//    ListNode *head = new ListNode(1);
    ListNode *ans = removeNthFromEnd(head, 2);
    while (ans->next) {
        printf("%d->", ans->val);   // expect：1->2->3->5
        ans = ans->next;
    }
    printf("%d", ans->val);
}

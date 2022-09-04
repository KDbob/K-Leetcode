// 剑指 Offer 24. 反转链表
// Created by kaide on 2021/5/3.
//

#include "KPrint.h"

using namespace std;

/**
 * 输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
 * 《方法一：迭代法》
 * @param head 链表的头节点
 * @return 反转后的链表的头节点
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
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
};

/**
 * 方法二：递归法
 */
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};




int main() {
    // create linked list 1->2->3->4->5
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode *res = Solution2().reverseList(head);
    printLinkedList(res);   // expect: ->5->4->3->2->1
//    printK(123);

}
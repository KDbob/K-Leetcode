// 328. 奇偶链表
// Created by bob on 2022/4/23.
//
#include "KStruct.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

using namespace std;

class Solution {
public:
ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr) {
        return head;
    }
    ListNode *evenHead = head->next;
    ListNode *oddPtr = head;
    ListNode *evenPtr = evenHead;
    while (evenPtr != nullptr && evenPtr->next != nullptr) {  // 循环的条件
        oddPtr->next = evenPtr->next;
        oddPtr = oddPtr->next;
        evenPtr->next = oddPtr->next;
        evenPtr = evenPtr->next;
    }
    oddPtr->next = evenHead;    // 合并两个链表
    return head;
}
};

int main() {
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));   // head = [1,2,3,4,5]
    ListNode *res = Solution().oddEvenList(head);   // expect: [1,3,5,2,4]
    return 0;
}
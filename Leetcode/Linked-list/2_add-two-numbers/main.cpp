//
// Created by bob on 2021/11/16.
//

#include <iostream>
#include "KPrint.h"

using namespace std;

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

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        int carry = 0;  // 注：是放在循环体外
        while (l1 || l2) {
            int n1 = l1->val ? l1->val : 0;
            int n2 = l2->val ? l2->val : 0;
            int sum = n1 + n2 + carry;
            if (!head) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            tail->next = new ListNode(1);
        }
        return head;
    }

};

int main() {
    auto *l1 = new ListNode(2, new ListNode(4, new ListNode(5)));
    auto *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    Solution *s = new Solution();
    ListNode *l3 = s->addTwoNumbers(l1, l2);  
    printLinkedList(l3);    //expect:7->0->0->1
}
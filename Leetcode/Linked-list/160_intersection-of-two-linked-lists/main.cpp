// 160. 相交链表
// Created by bob on 2022/3/11.
//
#include <unordered_set>
#include "KStruct.h"

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * 方法一：哈希集合
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> visited;
        ListNode *temp = headA;
        while (temp != nullptr) {
            visited.insert(temp);
            temp = temp->next;
        }
        temp = headB;
        while (temp != nullptr) {
            if (visited.count(temp)){
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    /**
     * 方法二：双指针法
     * @param headA
     * @param headB
     * @return
     */
ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr) return nullptr;
    ListNode *tempA = headA;
    ListNode *tempB = headB;
    while (tempA != tempB) {
        tempA = tempA == nullptr ? headA : tempA->next;
        tempB = tempB == nullptr ? headB : tempB->next;
    }
    return tempA;
}
};

int main() {
    Solution s = Solution();
    auto *crossList = new ListNode(8, new ListNode(4, new ListNode(5)));
    auto *listA = new ListNode(4, new ListNode(1, crossList));
    auto *listB = new ListNode(5, new ListNode(6, new ListNode(1, crossList)));
    ListNode *result = s.getIntersectionNode2(listA, listB);
    printf("%d", result->val);  // expect: 8
}
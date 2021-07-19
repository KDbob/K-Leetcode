// 234. 回文链表
// Created by kaide on 2021/5/5.
//
#include <iostream>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}

} ListNode;

ListNode *frontPointer;

/**
 * 判断一个链表是否为回文链表
 * 《递归前后指针同时判断法》
 * @param currentNode 头节点
 * @return 是否为回文串
 */
bool recursivelyCheck(ListNode* currentNode) {
    if (currentNode) {
        if (!recursivelyCheck(currentNode->next)) return false; // 递归入口：默认不会触发return false,只有当if (frontPointer->val != currentNode->val)条件
        if (frontPointer->val != currentNode->val) return false;
        frontPointer = frontPointer->next;
    }
    return true;
}

bool isPalindrome(ListNode* head) {
    frontPointer = head;
    return recursivelyCheck(head);
}


int main() {
    // 5->6->1->7->5
    ListNode *head1 = new ListNode(5, new ListNode(6, new ListNode(1, new ListNode(7, new ListNode(5)))));
    if (isPalindrome(head1)) {
        printf("isPalindrome\n");
    } else {
        printf("not palindrome\n");   // expect:not palindrome
    }

    // 1->2->2->1
    ListNode *head2 = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));
    if (isPalindrome(head2)) {
        printf("is palindrome\n");     // expect:is palindrome
    } else {
        printf("not palindrome\n");
    }
}
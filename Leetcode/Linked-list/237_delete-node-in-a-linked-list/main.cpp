// 237. 删除链表中的节点
// Created by kaide on 2021/4/26.
//
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

/**
 * 编写一个函数，使其可以删除某个链表中给定的（非末尾）节点。传入函数的唯一参数为 要被删除的节点
 * 《与下一个节点交换法》
 * @param node
 */
void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

int main(){
    ListNode *head = new ListNode(4);
    ListNode *node1 = new ListNode(5);
    ListNode *node2 = new ListNode(1);
    ListNode *node3 = new ListNode(9);
    head->next = node1;
    head->next->next = node2;
    head->next->next->next = node3;
    deleteNode(node2);
    while (head->next) {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("%d", head->val);
}

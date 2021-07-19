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
 * 因为，我们无法访问我们想要删除的节点 之前 的节点，我们始终不能修改该节点的 next 指针。相反，我们必须将想要删除的节点的值替换为它后面节点中的值，然后删除它之后的节点。
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

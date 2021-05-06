// 141. 环形链表
// Created by kaide on 2021/5/6.
//
#include <unordered_set>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}

} ListNode;

/**
 * 给定一个链表，判断链表中是否有环。
 * 《hash表法》
 * @param head 链表的头指针
 * @return 是否有环
 */
bool hasCycle(ListNode *head) {
    unordered_set<ListNode *> seen;
    while (head != nullptr) {
        if (seen.count(head)) {
            return true;
        }
        seen.insert(head);
        head = head->next;
    }
    return false;
}

int main() {
    ListNode *node4 = new ListNode(-4);
    ListNode *node2 = new ListNode(2, new ListNode(0, node4));
    node4->next = node2;
    ListNode *head1 = new ListNode(3, node2);
    // 建立回环链表 ->3->2->0->-4 (其中-4指向2)
    if (hasCycle(head1)) {
        printf("is cycle");     // expect: ture
    } else {
        printf("not cycle");
    }


}
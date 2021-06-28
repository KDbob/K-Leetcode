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
 * 《方法一：hash表法》
 * @param head 链表的头指针
 * @return 是否有环
 */
bool hasCycle1(ListNode *head) {
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

/**
 * 给定一个链表，判断链表中是否有环
 * 《方法二：Floyd 判圈算法》
 * @param head 链表的头指针
 * @return 是否有环
 */
bool hasCycle2(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (slow != fast) {
        if (fast->next == nullptr || fast->next == nullptr) {   // 这里只需要判断fash的后两个是否为空即可
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}

/**
 * 测试函数
 * @param head 链表的头指针
 * @param hasCycle 实现方法的函数指针（方法1 or 方法2）
 */
void testMethod(ListNode *head, bool (*hasCycle)(ListNode *h)) {
    if (hasCycle(head)) {
        printf("is cycle\n");
    } else {
        printf("not cycle\n");
    }
}

int main() {
    ListNode *node4 = new ListNode(-4);
    ListNode *node2 = new ListNode(2, new ListNode(0, node4));
    node4->next = node2;
    ListNode *head1 = new ListNode(3, node2);
    // 建立回环链表 ->3->2->0->-4 (其中-4指向2)
    testMethod(head1,hasCycle1);   // expect: is cycle
    testMethod(head1,hasCycle2);   // expect: is cycle

    ListNode *head2 = new ListNode(1, new ListNode(2));
    // 建立链表 ->1->2
    testMethod(head2,hasCycle1);    // expect:  not cycle
    testMethod(head2,hasCycle2);    // expect:  not cycle
}
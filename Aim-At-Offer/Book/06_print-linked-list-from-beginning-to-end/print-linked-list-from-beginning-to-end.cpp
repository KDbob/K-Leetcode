// 剑指 Offer 06. 从尾到头打印链表
// Created by kaide on 2021/3/17.
//
#include<iostream>
#include<vector>
#include "KStruct.h"

using namespace std;

/**
 * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {} // 初始化数据结构方法
};
*/

class Solution {
public:
/**
 * Topic 06: 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回)
 * 《使用栈的思想》
 * @param head 链表的头节点
 * @return 数组保存的反过来的值
 */
    vector<int> reversePrint(ListNode *head) {
        ListNode *next = head;
        vector<int> stack;
        while (next) {
            stack.push_back(next->val);
            next = next->next;
        }
        vector<int> res;
        while (!stack.empty()) {
            res.push_back(stack.back());
            stack.pop_back();
        }
        return res;
    }

};

/*--------------------------------------test func--------------------------------------------*/
int main() {
    auto *head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);

    auto s = new Solution();
    const vector<int> res = s->reversePrint(head);
    cout << "[" << res[0] << ", " << res[1] << ", " << res[2] << "]" << endl;   // expect: [2, 3, 1]

    return 0;
}
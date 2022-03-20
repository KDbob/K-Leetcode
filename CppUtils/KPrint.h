//
// Created by bob on 2021/9/12.
//

#ifndef K_LEETCODE_KPRINT_H
#define K_LEETCODE_KPRINT_H

#include "KStruct.h"
#include <vector>
#include <string>

using namespace std;
/**
 * 打印链表
 * @param head 链表的头指针
 */
void printLinkedList(ListNode *head) {
    while (head) {
        printf("->%d", head->val);
        head = head->next;
    }
    printf("\n");
}


void printVector(vector<int> nums) {
    for (int i = 0; i < nums.size(); ++i) {
        printf("%d", nums[i]);
        if (i != nums.size() - 1) printf(", ");
    }
    printf("\n");
}

void printVector(vector<string> strs) {
    for (int i = 0; i < strs.size(); ++i) {
        string str = strs[i];
        printf("%s", str.c_str());
        if (i != strs.size() - 1) printf(", ");
    }
    printf("\n");
}
#endif //K_LEETCODE_KPRINT_H

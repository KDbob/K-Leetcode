#### [328. 奇偶链表](https://leetcode-cn.com/problems/odd-even-linked-list/)

> #链表 #双指针

给定单链表的头节点 `head` ，将所有索引为奇数的节点和索引为偶数的节点分别组合在一起，然后返回重新排序的列表。

**第一个**节点的索引被认为是 **奇数** ， **第二个**节点的索引为 **偶数** ，以此类推。

请注意，偶数组和奇数组内部的相对顺序应该与输入时保持一致。

你必须在 `O(1)` 的额外空间复杂度和 `O(n)` 的时间复杂度下解决这个问题。

 

**示例 1:**

![img](https://assets.leetcode.com/uploads/2021/03/10/oddeven-linked-list.jpg)

```
输入: head = [1,2,3,4,5]
输出: [1,3,5,2,4]
```

**示例 2:**

![img](https://assets.leetcode.com/uploads/2021/03/10/oddeven2-linked-list.jpg)

```
输入: head = [2,1,3,5,6,4,7]
输出: [2,3,6,7,1,5,4]
```

 

## 方法一：双指针

### 1. 思路

使用双指针对链表遍历，最后再合并

- 一个指针指向奇数位，并构建奇数链表
- 一个指针指向偶数位，并构建偶数链表


### 2 编程

#### 2.1 数据结构

`ListNode *evenHead = head->next;`:偶链表的头指针

`ListNode *oddPtr = head;ListNode *evenPtr = evenHead;`分别指向奇偶节点的指针

#### 2.2 算法流程

0. 初始化evenhead用于保存偶链表的起点（head是奇链表的起点），初始化奇偶指针
1. 遍历链表，同时构建两个链表
   - 奇指针的下一个是偶指针的下一个
   - 偶指针的下一个是奇指针的下一个
2. 奇链表连接偶链表，返回head

#### 2.3 代码实现

```c++
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
```

### 3 复杂度分析

- 时间复杂度：O(n)
  - 需要遍历链表中的每个节点
- 空间复杂度：O(1)
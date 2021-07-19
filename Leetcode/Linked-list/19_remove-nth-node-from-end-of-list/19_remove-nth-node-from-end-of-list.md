#### [19. 删除链表的倒数第 N 个结点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)

给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

进阶：你能尝试使用一趟扫描实现吗？

 

示例 1：


输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
示例 2：

输入：head = [1], n = 1
输出：[]
示例 3：

输入：head = [1,2], n = 1
输出：[1]

# 解题思路

解题的关键在于拿到被删除的那个节点的前一个节点

## 一、栈

在遍历的过程中，将节点压入栈中。弹出第n个元素就是被删除的那个节点的前一个节点。

### 准备数据结构

stack<*p>

> 用于存储节点的指针

ListNode *next

### 算法流程

1. 遍历链表，将每个链表的指针压入栈中
2. 弹栈出n个元素
3. 栈顶元素对其下一个元素执行删除操作（链删除操作）

# 知识点总结

- 函数需要返回一个指针，如果用head指针去遍历，通过next一定会最后为空。因此需要加入一个中间变量保存head指针

  ```
  ListNode *dummy = new ListNode(0, head);
  ListNode *res = dummy->next;
  delete dummy;
  return res;
  ```

- 遍历的过程错误，数组越界[TODO]

  ```c++
  // 错误的形式
  ListNode *removeNthFromEnd(ListNode *head, int n) {
      ListNode *dummy = new ListNode(0, head);
      stack<ListNode *> stk;
      while (head) {
          stk.push(cur);
          cur = cur->next;
      }
  ```

  ```shell
  输入：[1],1
  Line 171: Char 16: runtime error: reference binding to misaligned address 0xbebebebebebec0b6 for type 'ListNode *', which requires 8 byte alignment (stl_deque.h)
  0xbebebebebebec0b6: note: pointer points here
  <memory cannot be printed>
  SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /usr/bin/../lib/gcc/x86_64-linux-gnu/9/../../../../include/c++/9/bits/stl_deque.h:180:16
  ```

  正确的形式：

  ```c++
  ListNode *removeNthFromEnd(ListNode *head, int n) {
      ListNode *dummy = new ListNode(0, head);
      stack<ListNode *> stk;
      ListNode *cur = dummy;
      while (cur) {
          stk.push(cur);
          cur = cur->next;
      }
  ```

  


#### [剑指 Offer 24. 反转链表](https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/)

定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

 

示例:

```
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
```


限制：

0 <= 节点个数 <= 5000

# 解题思路

## 方法一：迭代法

> 可以使用双指针不断迭代构造出反转链表。
>
> - curr指针用于处理每次遍历到的位置
>
> - prev指针滞后curr一位。
>
> - 用于将curr的前指针拼接到next上
>
>   例如pre指向1，curr指向2。可以将**curr->next = pre**，即实现了2->1。此时pre 指向 2->1。
>
>   例如pre指向2，curr指向3。可以将curr->next = pre，即实现了3->2->1。此时pre 指向 3->2->1。
>
>   ...

### 准备数据结构

ListNode *curr = head;

> curr指针用于处理每次遍历到的位置

ListNode *prev = nullptr;

> pre指针滞后curr一位，默认为空。也吻合了初始链表的尾指针一般为Null

### 算法流程

1. 以curr遍历原链表：while(curr)

   1. 准备临时数据结构ListNode *next指针暂存curr->next

      > 因为执行curr->next=pre后，会丢失next的信息。

   2. 将curr的下一个赋值为前指针，curr->next = pre，pre前进一位：pre=curr。
   3. curr前进一位：curr= next

2. 返回pre（此时pre指向curr的最后一个非空节点）

### 代码实现

```c++
ListNode *reverseList(ListNode *head) {
    ListNode *pre = nullptr;
    ListNode *curr = head;
    while (curr) {
        ListNode *next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }
    return pre;
}
```

## 方法二：递归（TODO）



# 知识点总结

- 一个指针的next如果被赋值后会改变，可能需要用临时变量暂存next的指针位置。
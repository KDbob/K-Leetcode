#### [剑指 Offer 06. 从尾到头打印链表](https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/)

# 解题思路

>  利用栈的思想，栈是先进后出的数据结构

1. 遍历单链表，将每个值压入栈中
2. 遍历栈，将栈中的元素取出放入数组中

### 准备的数据结构

栈：stack



# 知识点总结

1. 单链表的创建与使用（使用构造函数初始化结点）

```C++
struct ListNode
{
    double value;
    ListNode *next;
    //构造函数
    ListNode(double valuel, ListNode *nextl = nullptr)
    {
        value = value1;
        next = next1;
    }
};

// 创建节点
ListNode *secondPtr = new ListNode(13.5);
ListNode *head = new ListNode(12.5, secondPtr);
```


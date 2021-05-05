#### [234. 回文链表](https://leetcode-cn.com/problems/palindrome-linked-list/)

难度简单965收藏分享切换为英文接收动态反馈

请判断一个链表是否为回文链表。

**示例 1:**

```
输入: 1->2
输出: false
```

**示例 2:**

```
输入: 1->2->2->1
输出: true
```

**进阶：**
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

# 解题思路

## 方法一：复制到数组然后比较

## 方法二：递归（前后指针同时比较）

使用优雅的递归实现前后指针同时比较（设计较为复杂）

### 准备数据结构

全局变量：ListNode* frontPointer;

> 指针不断向后移动
>
> - 堆栈栈顶保存frontPointer=head

### 递归程序设计

1. 递归程序的Base Cell

   > 一般的递归程序打印过程：由后向前打印

```c++
bool recursivelyCheck(ListNode* currentNode) {
    if (currentNode) {
        if (!recursivelyCheck(currentNode->next)) return false;
    }
    return true;
}
```

- 递归到Base Cell一定是传了null的情况
  - 默认返回为true（同时代表这个是回文串），相当于程序完整递归完成，未出现一次false的情况。

1. 递归程序的实现

```C++
bool recursivelyCheck(ListNode* currentNode) {
    if (currentNode) {
        if (!recursivelyCheck(currentNode->next)) return false;
        if (frontPointer->val != currentNode->val) return false;
        frontPointer = frontPointer->next;
    }
    return true;
}
```

- 递归程序入口`if (!recursivelyCheck(currentNode->next)) return false`
  - 程序整体return true不会触发这个return false。
  - 只有当`if (frontPointer->val != currentNode->val)`条件满足时return false触发return false（传递作用）

## 方法三：双指针（TODO）



# 知识点总结

- 堆栈帧
  - 计算机需要在进入被调用函数之前跟踪它在当前函数中的位置（以及任何局部变量的值），通过运行时存放在堆栈中来实现（堆栈帧）
  - 在堆栈中存放好了数据后就可以进入被调用的函数。在完成被调用函数之后，他会弹出堆栈顶部元素，以恢复在进行函数调用之前所在的函数
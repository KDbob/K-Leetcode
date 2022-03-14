#### [2. 两数相加](https://leetcode-cn.com/problems/add-two-numbers/)

> #链表 #逻辑 #链表构造

给你两个 **非空** 的链表，表示两个非负的整数。它们每位数字都是按照 **逆序** 的方式存储的，并且每个节点只能存储 **一位** 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

 

**示例 1：**

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/01/02/addtwonumber1.jpg)

```
输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
```

```
输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.
```

> **解读**：逆序的含义就是头节点是个位数
>
> l1 = [2,4,3]表示为342，l2 = [5,6,4]表示为465

**示例 2：**

```
输入：l1 = [0], l2 = [0]
输出：[0]
```

**示例 3：**

```
输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
输出：[8,9,9,9,0,0,0,1]
```

#  解题思路

## 方法一：模拟法

### 1. 思路

因为链表本身就是逆序：

- 可以从个位(head)开始运算，和链表的遍历顺序相同

使用模拟手算加法：

- 个位、百位、千位分别和对应的值相加
- 对应位逢10进1位


### 2 编程

#### 2.1 数据结构

- 两个指针用于构造返回的结果链表

  ```c++
  ListNode *head = nullptr;
  ListNode *tail = nullptr;
  ```

- `int carry = 0;`进位标志位（只会取0或1）

  > 放在循环体外面作用是用于识别遍历结束后是否还有进位

#### 2.2 算法流程

1. 遍历两个链表

   - 计算该位的两数之和
     - sum = n1 + n2 + carry;
     - carry = sum / 10;

   - 构造链表
     - tail -> next = ListNode(sum % 10)

2. 如果遍历结束carry>0，还需在tail后再补一个节点：tail->next = ListNode(1)

#### 2.3 代码实现

##### 遍历的循环体结构★

> 只要有一方不为空，就应该继续遍历

```c++
while(l1 || l2) {
  // 运算代码
  if(l1) l1 = l1 -> next;
  if(l2) l2 = l2 -> next;
}
```

##### 构造链表的循环结构🐱

> head指针作用是返回头节点，tail指针作用是构建后续的节点

```c++
ListNode *head = nullptr;
ListNode *tail = nullptr;
while(...) {
	if (!head) {
		head = tail = new ListNode();
	} else {
		tail->next = new ListNode();
		tail = tail->next;
	}
}
return head;
```

##### 完整代码

```c++
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    int carry = 0;  // 注：是放在循环体外
    while (l1 || l2) {
        int n1 = l1->val ? l1->val : 0;
        int n2 = l2->val ? l2->val : 0;
        int sum = n1 + n2 + carry;
        if (!head) {
            head = tail = new ListNode(sum % 10);
        } else {
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }
        carry = sum / 10;
        if (l1) {
            l1 = l1->next;
        }
        if (l2) {
            l2 = l2->next;
        }
    }
    if (carry > 0) {
        tail->next = new ListNode(1);
    }
    return head;
}
```



## 复杂度分析

- 时间复杂度：$O(max⁡(m,n))$
- 空间复杂度：$O(1)$

# 总结

- 整体逻辑需要思维缜密
  - 遍历循环体的条件设计
  - 遍历结束后carry>0，还需要补个节点

- 构造链表的基本方法

#### [160. 相交链表](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/)

> #双指针 #证明

给你两个单链表的头节点 `headA` 和 `headB` ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 `null` 。

图示两个链表在节点 `c1` 开始相交**：**

[![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_statement.png)](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_statement.png)

题目数据 **保证** 整个链式结构中不存在环。

**注意**，函数返回结果后，链表必须 **保持其原始结构** 。

**自定义评测：**

**评测系统** 的输入如下（你设计的程序 **不适用** 此输入）：

- `intersectVal` - 相交的起始节点的值。如果不存在相交节点，这一值为 `0`
- `listA` - 第一个链表
- `listB` - 第二个链表
- `skipA` - 在 `listA` 中（从头节点开始）跳到交叉节点的节点数
- `skipB` - 在 `listB` 中（从头节点开始）跳到交叉节点的节点数

评测系统将根据这些输入创建链式数据结构，并将两个头节点 `headA` 和 `headB` 传递给你的程序。如果程序能够正确返回相交节点，那么你的解决方案将被 **视作正确答案** 。

 

**示例 1：**

[![img](https://assets.leetcode.com/uploads/2021/03/05/160_example_1_1.png)](https://assets.leetcode.com/uploads/2018/12/13/160_example_1.png)

```
输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
输出：Intersected at '8'
解释：相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。
从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,6,1,8,4,5]。
在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
```

**示例 2：**

[![img](https://assets.leetcode.com/uploads/2021/03/05/160_example_2.png)](https://assets.leetcode.com/uploads/2018/12/13/160_example_2.png)

```
输入：intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
输出：Intersected at '2'
解释：相交节点的值为 2 （注意，如果两个链表相交则不能为 0）。
从各自的表头开始算起，链表 A 为 [1,9,1,2,4]，链表 B 为 [3,2,4]。
在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
```

**示例 3：**

[![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_example_3.png)](https://assets.leetcode.com/uploads/2018/12/13/160_example_3.png)

```
输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
输出：null
解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。
由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
这两个链表不相交，因此返回 null 。
```

 

**提示：**

- `listA` 中节点数目为 `m`
- `listB` 中节点数目为 `n`
- `1 <= m, n <= 3 * 104`
- `1 <= Node.val <= 105`
- `0 <= skipA <= m`
- `0 <= skipB <= n`
- 如果 `listA` 和 `listB` 没有交点，`intersectVal` 为 `0`
- 如果 `listA` 和 `listB` 有交点，`intersectVal == listA[skipA] == listB[skipB]`





# 解题

## 方法一：哈希集合

#### 做法

- 先遍历head A，将headA的每个节点都加入哈希集合
- 然后再遍历B，对于遍历到的每个节点，判断是否在集合中

#### 复杂度分析

- 时间复杂度：$O(m + n)$
- 空间复杂度：$O(m)$
  - m是链表headA的长度


## 方法二：双指针

> 可以将空间复杂度降到$O(1)$

### 1. 思路

初始创建两个指针pA和pB，分别执行两个链表的头节点headA和headB，然后将两个指针依次遍历两个链表的每个节点：

- 每次操作，pA和pB同时遍历
- 如果pA为空，pA指向headB；同理如果pB为空，pB指向headA。

当pA和pB相等时（指向同一个节点or都为空）返回该节点，即为所求。

#### 证明：

> ​	假设链表headA不相交的部分有a个节点，链表headB得不相交部分有b个节点，两个链表相交的部分有c个节点，则有a+c=m，b+c=n

- 情况一：两个链表相交

  - 如果a = b，则两个指针会同时到达两个链表相交的节点，此时返回相交的节点。
- 如果a ≠ b，pA移动了a+c+b次，pB移动了b+c+a次，之后两个指针会同时达到两个链表相交的节点。
- 情况二：两个链表不相交

  - 如果 m = n，则两个指针会同时到达链表的尾节点，然后变成空值，返回null
  - 如果 m ≠ n，则pA移动了m+n次，pB移动了n+m次后，两个指针会同时变成空值null，返回null


### 2 编程

#### 2.1 数据结构

`ListNode *tempA = headA;`：指向headA的指针，遍历用

`ListNode *tempB = headB;`：指向headB的指针，遍历用

#### 2.2 算法流程

0. 如果有一个链表为空，返回空
1. 双指针tempA和tempB同时遍历链表A和链表B：
   - 如果tempA遍历到空，转到链表B（tempA=headB）
   - 如果tempB遍历到空，转到链表A（tempB=headA）
2. 返回tempA

#### 2.3 代码实现

```c++
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr) return nullptr;
    ListNode *tempA = headA;
    ListNode *tempB = headB;
    while (tempA != tempB) {
        tempA = tempA == nullptr ? headA : tempA->next;
        tempB = tempB == nullptr ? headB : tempB->next;
    }
    return tempA;
}
```

### 3 复杂度分析

- 时间复杂度：$O(m+n)$
- 空间复杂度：$O(1)$


# 总结

- 证明双指针是可行的，需要分步骤和清晰
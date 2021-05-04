#### [21. 合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/)

将两个升序链表合并为一个新的 **升序** 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

![img](https://assets.leetcode.com/uploads/2020/10/03/merge_ex1.jpg)

输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
示例 2：

输入：l1 = [], l2 = []
输出：[]
示例 3：

输入：l1 = [], l2 = [0]
输出：[0]

# 解题思路

## 方法一：递归构建

#### **分析递归公式**

$$
\left\{\begin{matrix} 
list1[0]+merge(list1[1:], list2) \quad list1[0]<list2[0]
\\list2[0]+merge(list1, list2[2:]) \quad otherwise
\end{matrix}\right.
$$

#### **分析递归结束条件**（也是程序执行的初始构建步骤）

> 因为链表最终尾部合并的时候l1,l2其中一定有一个为空，容易写出如下的递归结束条件

```C++
    if (!l1 || !l2) {
        if  (!l1) {
            return l2;
        } else {
            return l1;
        }
    }
```

#### 代码实现

> 根据递归结束条件和递归公式后的代码实现：

```C++
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (!l1 || !l2) {
        if  (!l1) {
            return l2;
        } else {
            return l1;
        }
    }
    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}
```



## 方法二：迭代构建（TODO）
#### [141. 环形链表](https://leetcode-cn.com/problems/linked-list-cycle/)

给定一个链表，判断链表中是否有环。

如果链表中有某个节点，可以通过连续跟踪 `next` 指针再次到达，则链表中存在环。 为了表示给定链表中的环，我们使用整数 `pos` 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 `pos` 是 `-1`，则在该链表中没有环。**注意：`pos` 不作为参数进行传递**，仅仅是为了标识链表的实际情况。

如果链表中存在环，则返回 `true` 。 否则，返回 `false` 。

 

**进阶：**

你能用 *O(1)*（即，常量）内存解决此问题吗？

 

**示例 1：**

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist.png)

```
输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。
```

**示例 2：**

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test2.png)

```
输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。
```

**示例 3：**

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test3.png)

```
输入：head = [1], pos = -1
输出：false
解释：链表中没有环。
```

 

**提示：**

- 链表中节点的数目范围是 `[0, 104]`
- `-105 <= Node.val <= 105`
- `pos` 为 `-1` 或者链表中的一个 **有效索引** 。

# 解题思路

## 方法一：hash表

遍历链表，可以用hash表记录每个节点是否出现过，如果再次出现说明有环。

### 准备数据结构

`unordered_set<ListNode *> seen;`

> 标记每个节点是否出现过

### 算法流程 

1. 遍历链表

   - 如果出现过，说明有环

   - 如果未出现过，加入到hash表中

### 算法实现

```C++
bool hasCycle1(ListNode *head) {
    unordered_set<ListNode *> seen;
    while (head != nullptr) {
        if (seen.count(head)) {
            return true;
        }
        seen.insert(head);
        head = head->next;
    }
    return false;
}
```



## 方法二：快慢指针（实现$O(1)$空间复杂度）

> Floyd 判圈算法

假想「乌龟」和「兔子」在链表上移动，「兔子」跑得快，「乌龟」跑得慢。当「乌龟」和「兔子」从链表上的同一个节点开始移动时，如果该链表中没有环，那么「兔子」将一直处于「乌龟」的前方；如果该链表中有环，那么「兔子」会先于「乌龟」进入环，并且一直在环内移动。等到「乌龟」进入环时，由于「兔子」的速度快，它一定会在某个时刻与乌龟相遇，即套了「乌龟」若干圈。

## 算法实现

```c++
bool hasCycle2(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (slow != fast) {
        if (fast->next == nullptr || fast->next == nullptr) {   // 这里只需要判断fast的后两个是否为空即可
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}
```

注：这里快慢指针的初始位置不相同，是因为使用了while循环：判定条件先执行。

> 改成do-while形式快慢指针可以在同一位置（head）

# 知识点总结

- C++中的set数据类型

  ```C++
  #include <unordered_set>
  unordered_set<ListNode *> seen;
  seen.count(head) 	// 判断在集合中是否出现过
  seen.insert(head)	// 保存到集合中
  ```

- C语言中的函数指针使用

  > [参考博客地址](https://blog.csdn.net/zj1131190425/article/details/92065897)

  ```c++
  #include <iostream>
  #include <algorithm>
  #include <cmath>
   
  using namespace std;
   
  double cal_m1(int lines)
  {
  	return 0.05 * lines;
  } 
   
  double cal_m2(int lines)
  {
  	return 0.5 * lines;
  }
   
  void estimate(int line_num, double (*pf)(int lines))
  {
  	cout << "The " << line_num << " need time is: " << (*pf)(line_num) << endl; 
  }
   
   
  int main(int argc, char *argv[])
  {
  	int line_num = 10;
  	// 函数名就是指针，直接传入函数名
  	estimate(line_num, cal_m1);
  	estimate(line_num, cal_m2); 
  	return 0;
  }
  ```

  


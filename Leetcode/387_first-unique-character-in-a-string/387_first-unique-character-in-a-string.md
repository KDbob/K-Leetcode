#### [387. 字符串中的第一个唯一字符](https://leetcode-cn.com/problems/first-unique-character-in-a-string/)

给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

 

示例：

```c++
s = "leetcode"
返回 0

s = "loveleetcode"
返回 2
```

# 解题思路

容易想到hash表

### 准备数据结构

hashmap<int,int> map;

> 字符也是以ASCII的方式存储，即数字。

hash表有三种解题思路：

### 一、用hash表记录每个字母的出现频次

1. 第一遍遍历，遍历字符串，记录每个字母的频次

2. 第二遍遍历，遍历字符串，如果这个字符出现的频次是1，返回该字母

   > 该字母即为第一次出现的只出现一次的第一个字母

### 二、用hash表记录每个字母会否出现

1. 第一遍遍历，遍历字符串，记录每个字母是否只出现一次

   - 第一次将hash表记录为<num，num>
   - 该字符重复出现的时候，将hash表记录为<num，-1>

2. 第二遍遍历，遍历字符串，如果这个字符的hash值=num返回

   > 该字母即为第一次出现的只出现一次的第一个字母

### 三、用hash表+队列一次遍历实现

#### 准备数据结构

queen<pairs<int,init>> q;

记录该字符和字符出现的位置。

>  使用了「延迟删除」这一技巧。也就是说，即使队列中有一些字符出现了超过一次，但它只要不位于队首，那么就不会对答案造成影响，我们也就可以不用去删除它。只有当它前面的所有字符被移出队列，它成为队首时，我们才需要将它移除。

#### 算法流程

0. 按方法二的方式，第一次遍历字符串。记录每个字母是否只出现一次
   - 第一次将hash表记录为<num，index>
   - 该字符重复出现的时候，将hash表记录为<num，-1>

1. 遍历的同时检查字母是只出现一次

   - 如果第一次出现将该数字插入到队尾

   - 一旦字母已经不是第一次出现（通过hash表判断）
     - 检测是否和队头元素相同，相同的话pop队头元素

#### 原理分析

- 因为插入到队尾的，都是当时认为只出现一次的字母。
  - 多次出现的字母也不会再继续插入到队列队尾
- 遍历时检测每个字母，如果和队头的相同，pop(用while循环将队列中队头为-1的都pop)，说明抵消了重复的。
  - 一直存在队头的字母，说明没有字母和他抵消。即**第一个唯一的字母**
  - 即使队列里面有字母不被抵消，也不影响输出。只能说明**第一个唯一的字母**在它前面

#### 代码实现

```c++
int firstUniqChar(string s) {
    unordered_map<char, int> mp;
    queue<pair<char, int>> q;
    for (int i = 0; i < s.size(); ++i) {
        if (!mp.count(s[i])) {  // 如果该字母第一次出现
            mp[s[i]] = i;
            q.emplace(s[i], i);
        } else {
            mp[s[i]] = -1;
            while (!q.empty() && mp[q.front().first] == -1) {  // 说明有个出现第二次的字母
                q.pop();
            }
        }
    }
    return q.empty() ? -1 : q.front().second;
}
```

#### 复杂度分析

时间复杂度：$O(n)$

> 遍历字符串的时间复杂度为 O(n)，而在遍历的过程中我们还维护了一个队列，由于每一个字符最多只会被放入和弹出队列最多各一次，因此维护队列的总时间复杂度为 $O(|∑|)$
>

空间复杂度：$O(\Sigma)$

最多需要字母表的hashmap和queen

# 知识点总结

- C++中unorder_map的方法

  ```c++
  mp.count(s[i])
  //count
  //returns the number of elements matching specific key 
  //(public member function)
  ```

- C++中队列的创建

  ```c++
  queue<pair<char, int>> q;
  ```

  

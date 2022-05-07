#### [347. 前 K 个高频元素](https://leetcode-cn.com/problems/top-k-frequent-elements/)

> #堆排序 #快速排序

给你一个整数数组 `nums` 和一个整数 `k` ，请你返回其中出现频率前 `k` 高的元素。你可以按 **任意顺序** 返回答案。

 

**示例 1:**

```
输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
```

**示例 2:**

```
输入: nums = [1], k = 1
输出: [1]
```

 

**提示：**

- `1 <= nums.length <= 105`
- `k` 的取值范围是 `[1, 数组中不相同的元素的个数]`
- 题目数据保证答案唯一，换句话说，数组中前 `k` 个高频元素的集合是唯一的

 

**进阶：**你所设计算法的时间复杂度 **必须** 优于 `O(n log n)` ，其中 `n` 是数组大小。

## 方法一：堆排序

### 1. 思路

- 首先将频次映射成map

- 遍历map，并同时建立小根堆（size=k）

  > ★为什么是小根堆？
  >
  > - 因为建堆的时候只操作堆顶元素，并且小根堆堆顶元素最小，**堆顶最小的元素都比未入堆的元素大**，遍历完毕时可以说明这个堆中的元素恰好是前K个大元素。


### 2 编程

#### 2.1 数据结构

#### 2.2 算法流程

1. 将频次映射成map<数：频次>

2. 遍历map，同时建立小根堆<数：频次>

   - 如果size<k，直接建堆

   - 如果size=k

     > 为了保持堆的元素维持在k，如果有比堆顶元素小的，加入堆并重新调整

     - 如果频次>堆顶元素，出堆顶并重新调整

3. 返回小根堆中的所有数

#### 2.3 代码实现

```c++
static bool cmp(pair<int, int>& m, pair<int, int>& n) {
    return m.second > n.second;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> occurrences;
    for (auto &v: nums) {
        occurrences[v]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
    for (auto &[nums, count] : occurrences) {
        if (q.size() < k) {     // 直接建立小根堆
            q.emplace(nums, count);
        } else { 
            if (q.top().second < count) {   // 重新调整小根堆
                q.pop();
                q.emplace(nums, count);
            }
        }
    }
    vector<int> ret;
    while (!q.empty()) {
        ret.push_back(q.top().first);
        q.pop();
    }
    return ret;
}
```

### 3 复杂度分析



# 总结

- C++中的优先队列（堆）的使用

  ```c++
  priority_queue<int, vector<int>, less<int>> q;	// 大根堆
  q.push(1);
  q.push(3);
  q.push(2);
  q.push(6);
  q.push(4);
  while (!q.empty()) {
      printf("%d", q.top());	// expect: 64321
      q.pop();
  }
  ```

- Python中的优先队列（堆）的使用

  ```python
  import heapq
    
  # initializing list
  li = [5, 7, 9, 1, 3]
    
  # using heapify to convert list into heap
  heapq.heapify(li)
    
  # printing created heap
  print ("The created heap is : ",end="")
  print (list(li))
    
  # using heappush() to push elements into heap
  # pushes 4
  heapq.heappush(li,4)
    
  # printing modified heap
  print ("The modified heap after push is : ",end="")
  print (list(li))
    
  # using heappop() to pop smallest element
  print ("The popped and smallest element is : ",end="")
  print (heapq.heappop(li))
  ```

  - 如果容器中是元组，按顺序（从左到右比较）

    `heapq.heappush(heap, (val, key))`

  - 出堆再调整等同于以下语句

    ```python
    heapq.heappop(heap)
    heapq.heappush(heap, (val, key))
    # 等同于：
    heapq.heapreplace(heap, (val, key))
    ```

- python.collections计数字典作用等同于C++ 中的遍历代码：

  ```python
  count = collections.Counter(nums)
  ```

  ```c++
  unordered_map<int, int> occurrences;
          for (auto &v: nums) {
              occurrences[v]++;
          }
  ```

参考资料：

- [geeksforgeeks：Heap queue (or heapq) in Python](https://www.geeksforgeeks.org/heap-queue-or-heapq-in-python/?ref=lbp)


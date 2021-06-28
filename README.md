# K-Leetcode
Leetcode practice

### File Structure

> Each Topic directory contains code and note.The main.cpp contains test cases and can executed directly。
>
> 每个题目文件夹包含源码和笔记。其中main.cpp里面包含测试用例，可以直接执行。
```
├── Aim-At-Offer
│   ├── 03_find-repeat-num
│   │   ├── 03_find_repeat_num.md
│   │   └── main.cpp
├── CMakeLists.txt
├── Leetcode
│   ├── 119_number-of-1-bits
│   │   ├── 119_number-of-1-bits.md
│   │   └── main.cpp
├── README.md
```


### Order of Topic
[初级算法](https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x2gy9m/)

### Topic list

#### 数组

| 题目名称                                                     | 文件位置（解题、源码）                                       | 实现的方法         |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------ |
| [141. 环形链表](https://leetcode-cn.com/problems/linked-list-cycle/) | [解题说明](Leetcode/Linked-list/141_linked-list-cycle/141_linked-list-cycle.md)、[code](Leetcode/Linked-list/141_linked-list-cycle/main.cpp) | hash表✔️、快慢指针✔️ |

#### 动态规划

| 题目名称                                                     | 文件位置（解题、源码）                                       | 实现的方法          |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------- |
| [53. 最大子序和](https://leetcode-cn.com/problems/maximum-subarray/) | [解题说明](Leetcode/Dynamic/53_maximum-subarray/53_maximum-subarray.md)、[code](Leetcode/Dynamic/53_maximum-subarray/main.cpp) | 动态规划✔️、分而治之 |
| [122. 买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/) | [解题说明](Leetcode/Dynamic/122_best-time-to-buy-and-sell-stock-ii/122_best-time-to-buy-and-sell-stock-ii.md)、[code](Leetcode/Dynamic/122_best-time-to-buy-and-sell-stock-ii/main.cpp) | 动态规划✔️           |
| [198. 打家劫舍](https://leetcode-cn.com/problems/house-robber/) | [解题说明](Leetcode/Dynamic/198_house-robber/198_house-robber.md)、[code](Leetcode/Dynamic/198_house-robber/main.cpp) | 动态规划✔️           |

#### 设计问题

| 题目名称                                                     | 文件位置（解题、源码）                                       | 实现的方法          |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------- |
| [155. 最小栈](https://leetcode-cn.com/problems/min-stack/)   | [解题说明](Leetcode/Design/155_min-stack/155_min-stack.md)、[code](Leetcode/Design/155_min-stack/main.cpp) | 辅助栈✔️             |
| [384. 打乱数组](https://leetcode-cn.com/problems/shuffle-an-array/) | [解题说明](Leetcode/Design/384_shuffle-an-array/384_shuffle-an-array.md)、[code](Leetcode/Design/384_shuffle-an-array/main.cpp) | 随机抽取✔️、洗牌算法 |

#### 数学问题

| 题目名称                                                     | 文件位置（解题、源码）                                       | 实现的方法                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ | --------------------------------- |
| [13. 罗马数字转整数](https://leetcode-cn.com/problems/roman-to-integer/) | [解题说明](Leetcode/Math/13_roma-to-int/13_roman-to-integer.md)、[code](Leetcode/Math/13_roma-to-int/main.cpp) | 模拟法✔️                           |
| [204. 计数质数](https://leetcode-cn.com/problems/count-primes/) | [解题说明](Leetcode/Math/204_count-primes/204_count-primes.md)、[code](Leetcode/Math/204_count-primes/main.cpp) | 枚举法✔️、埃氏筛✔️                  |
| [326. 3的幂](https://leetcode-cn.com/problems/power-of-three/) | [解题说明](Leetcode/Math/326_power-of-three/326_power-of-three.md)、[code](Leetcode/Math/326_power-of-three/main.cpp) | 三进制✔️、对数公式✔️、利用整数限制✔️ |
| [412. Fizz Buzz](https://leetcode-cn.com/problems/fizz-buzz/) | [code](Leetcode/Math/412_fizz-buzz/main.cpp)                 | 字符串连接✔️                       |

#### 其他

| 题目名称                                                     | 文件位置（解题、源码）                                       | 实现的方法             |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ---------------------- |
| [20. 有效的括号](https://leetcode-cn.com/problems/valid-parentheses/) | [解题说明](Leetcode/Other/20_valid-parentheses/20_valid-parentheses.md)、[code](Leetcode/Other/20_valid-parentheses/main.cpp) | 栈匹配✔️                |
| [190. 颠倒二进制位](https://leetcode-cn.com/problems/reverse-bits/) | [解题说明](Leetcode/Other/190_reverse-bits/190_reverse-bits.md)、[code](Leetcode/Other/190_reverse-bits/main.cpp) | 逐位颠倒✔️、位运算分治  |
| [191. 位1的个数](https://leetcode-cn.com/problems/number-of-1-bits/) | [解题说明](Leetcode/Other/119_number-of-1-bits/119_number-of-1-bits.md)、[code](Leetcode/Other/119_number-of-1-bits/main.cpp) | 循环检查✔️、位运算优化✔️ |
| [缺失数字](https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof/) | [解题说明](Leetcode/Other/xxx_missing-number/xxx_missing-number.md)、[code](Leetcode/Other/xxx_missing-number/main.cpp) | 异或运算✔️              |


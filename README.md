## 目录结构 File Structure 

> 每个题目文件夹包含源码和笔记。其中main.cpp里面包含测试用例，可以直接执行。

```
├── CMakeLists.txt
├── Leetcode
│   ├── 119_number-of-1-bits
│   │   ├── 119_number-of-1-bits.md
│   │   └── main.cpp
├── README.md
```

## 标记&符号 Tags&Symbols 

> markdown中的一些记号，自动化分类和提示作用

### 标记 tags 

> 后期用作分类

- #数学：数学问题
- #数组：数组相关

### 符号 Symbol 

- ★ ：重要，说不定能举一反三
- 💡：没想到
- 🐱：巧妙，以后我也这么做



# 分类 Category 

## 数组

| 题目名称（难度）                                             | 解题、源码                                                   | 实现方法                    |
| ------------------------------------------------------------ | ------------------------------------------------------------ | --------------------------- |
| [1. 两数之和](https://leetcode-cn.com/problems/two-sum/)（易） | [C++](Leetcode/Array&String/1_two-sum/main.cpp)              | 暴力破解✔️、哈希表           |
| [15. 三数之和](https://leetcode-cn.com/problems/3sum/)（中） | [解题](Leetcode/Array&String/15_3sum/readme.md)、[C++](Leetcode/Array&String/15_3sum/main.cpp)、[python](Leetcode/Array&String/15_3sum/main.py) | 排序+双指针✔️                |
| [26. 删除有序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)（易） | [解题](Leetcode/Array&String/26_remove-duplicates-from-sorted-array/readme.md)、[C++](Leetcode/Array&String/26_remove-duplicates-from-sorted-array/readme.md) | 双指针✔️                     |
| [33. 搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/) | [解题](Leetcode/Array&String/33_search-in-rotated-sorted-array/readme.md)、[C++](Leetcode/Array&String/33_search-in-rotated-sorted-array/main.cpp) | 二分查找✔️                   |
| [34. 在排序数组中查找元素的第一个和最后一个位置](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/) | [解题](Leetcode/Sort&Search/34_find-first-and-last-position-of-element-in-sorted-array/readme.md)、[C++](Leetcode/Sort&Search/34_find-first-and-last-position-of-element-in-sorted-array/main.cpp) | 二分查找✔️                   |
| [36. 有效的数独](https://leetcode-cn.com/problems/valid-sudoku/)（中） | [解题](Leetcode/Array&String/36_valid-sudoku/readme.md)、[C++](Leetcode/Array&String/36_valid-sudoku/main.cpp) | 一次遍历✔️                   |
| [48. 旋转图像](https://leetcode-cn.com/problems/rotate-image/)（中） | [解题](Leetcode/Array&String/48_rotate-image/readme.md)、[C++](Leetcode/Array&String/48_rotate-image/main.cpp) | 映射法✔️                     |
| [49. 字母异位词分组](https://leetcode-cn.com/problems/group-anagrams/)（中） | [解题](Leetcode/Array&String/46_group-anagrams)、[C++](Leetcode/Array&String/46_group-anagrams/main.cpp)、[python](Leetcode/Array&String/46_group-anagrams/main.py) | 哈希表✅                     |
| [66. 加一](https://leetcode-cn.com/problems/plus-one/)（易） | [解题](Leetcode/Array&String/66_plus-one/readme.md)、[C++](Leetcode/Array&String/66_plus-one/main.cpp) | 数组遍历✔️                   |
| [74. 搜索二维矩阵](https://leetcode-cn.com/problems/search-a-2d-matrix/) | [解题](Leetcode/Array&String/74_search-a-2d-matrix/readme.md)、[C++](Leetcode/Array&String/74_search-a-2d-matrix/main.cpp) | 两次二分查找✔️、一次二分查找 |
| [121. 买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)（易～中） | [解题](Leetcode/Array&String/121_best-time-to-buy-and-sell-stock/readme.md)、[C++](Leetcode/Array&String/121_best-time-to-buy-and-sell-stock/main.cpp) | 一次遍历✔️、暴力法           |
| [136. 只出现一次的数字](https://leetcode-cn.com/problems/single-number/)（易） | [解题](Leetcode/Array&String/136_single-number/readme.md)、[C++](Leetcode/Array&String/136_single-number/main.cpp) | 位运算✔️                     |
| [141. 环形链表](https://leetcode-cn.com/problems/linked-list-cycle/) | [解题](Leetcode/Linked-list/141_linked-list-cycle/readme.md)、[C++](Leetcode/Linked-list/141_linked-list-cycle/main.cpp) | hash表✔️、快慢指针✔️          |
| [189. 旋转数组](https://leetcode-cn.com/problems/rotate-array/)（中） | [解题](Leetcode/Array&String/48_rotate-image/readme.md)、[C++](Leetcode/Array&String/48_rotate-image/main.cpp) | 使用额外的数组✔️、环状替换   |
| [283. 移动零](https://leetcode-cn.com/problems/move-zeroes/)（易） | [解题](Leetcode/Array&String/283_move-zeroes/readme.md)、[C++](Leetcode/Array&String/283_move-zeroes/main.cpp) | 双指针法（i、ii）✔️          |
| [350. 两个数组的交集 II](https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/)（易） | [解题](Leetcode/Array&String/136_single-number/main.cpp)、[C++](Leetcode/Array&String/350_intersection-of-two-arrays-ii/main.cpp) | hash表✔️                     |

## 字符串

| 题目名称（难度）                                             | 解题说明、源码                                               | 实现的方法      |
| ------------------------------------------------------------ | ------------------------------------------------------------ | --------------- |
| [344. 反转字符串](https://leetcode-cn.com/problems/reverse-string/)（易） | [解题说明](Leetcode/String/344_reverse-string/344_reverse-string.md)、[C++](Leetcode/String/344_reverse-string/main.cpp) | 双指针✔️         |
| [7. 整数反转](https://leetcode-cn.com/problems/reverse-integer/)（易） | [解题说明](Leetcode/String/7_reverse-integer/7_reverse-integer.md)、[C++](Leetcode/String/7_reverse-integer/main.cpp) | 数字法✔️         |
| [387. 字符串中的第一个唯一字符](https://leetcode-cn.com/problems/first-unique-character-in-a-string/)（易） | [解题说明](Leetcode/String/387_first-unique-character-in-a-string/387_first-unique-character-in-a-string.md)、[C++](Leetcode/String/387_first-unique-character-in-a-string/main.cpp) | hash表✔️         |
| [242. 有效的字母异位词](https://leetcode-cn.com/problems/valid-anagram/)（易） | [解题说明](Leetcode/String/242_valid-anagram/242_valid-anagram.md)、[C++](Leetcode/String/242_valid-anagram/main.cpp) | hash表✔️、排序   |
| [125. 验证回文串](https://leetcode-cn.com/problems/valid-palindrome/)（易） | [解题说明](Leetcode/String/125_valid-palindrome/125_valid-palindrome.md)、[C++](Leetcode/String/125_valid-palindrome/main.cpp) | 双指针✔️         |
| [8. 字符串转换整数 (atoi)](https://leetcode-cn.com/problems/string-to-integer-atoi/)（中～难） | [解题说明](Leetcode/String/8_string-to-integer-atoi/8_string-to-integer-atoi.md)、[C++](Leetcode/String/8_string-to-integer-atoi/main.cpp) | 逻辑式✔️、自动机 |
| [28. 实现 strStr()](https://leetcode-cn.com/problems/implement-strstr/)（易） | [解题说明](Leetcode/String/28_implement-strstr/28_implement-strstr.md)、[C++](Leetcode/String/28_implement-strstr/main.cpp) | 简单匹配✔️       |
| [38. 外观数列](https://leetcode-cn.com/problems/count-and-say/)（中） | [解题说明](Leetcode/String/38_count-and-say/38_count-and-say.md)、[C++](Leetcode/String/38_count-and-say/main.cpp) | 分治法✔️         |
| [14. 最长公共前缀](https://leetcode-cn.com/problems/longest-common-prefix/)（易） | [解题说明](Leetcode/String/14_longest_common_prefix/14_longest-common-prefix.md)、[C++](Leetcode/String/14_longest_common_prefix/main.cpp) | 纵向扫描✔️       |

## 链表

| 题目名称（难度）                                             | 解题、源码                                                   | 实现的方法        |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ----------------- |
| [2. 两数相加](https://leetcode-cn.com/problems/add-two-numbers/)（易～中） | [解题](Leetcode/Linked-list/2_add-two-numbers/readme.md)、[C++](Leetcode/Linked-list/2_add-two-numbers/main.cpp)、[Python](Leetcode/Linked-list/2_add-two-numbers/main.py) | 模拟法✅           |
| [237. 删除链表中的节点](https://leetcode-cn.com/problems/delete-node-in-a-linked-list/) | [C++](Leetcode/Linked-list/237_delete-node-in-a-linked-list/main.cpp) | 与下一个节点交换✔️ |
| [19. 删除链表的倒数第 N 个结点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)（中） | [解题](Leetcode/Linked-list/19_remove-nth-node-from-end-of-list/readme.md)、[C++](Leetcode/Linked-list/19_remove-nth-node-from-end-of-list/main.cpp) | 栈✔️               |
| [160. 相交链表](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/)（中） | [解题](Leetcode/Linked-list/160_intersection-of-two-linked-lists/readme.md)、[C++](Leetcode/Linked-list/160_intersection-of-two-linked-lists/main.cpp)、[Python](Leetcode/Linked-list/160_intersection-of-two-linked-lists/main.py) | 哈希集合、双指针✔️ |
| [328. 奇偶链表](https://leetcode-cn.com/problems/odd-even-linked-list/)（中） | [解题](Leetcode/Linked-list/328_odd-even-linked-list)、[C++](Leetcode/Linked-list/328_odd-even-linked-list/main.cpp)、[python](Leetcode/Linked-list/328_odd-even-linked-list/main.py) | 双指针✅           |

## 动态规划

| 题目名称                                                     | 文件位置（解题、源码）                                       | 实现的方法            |
| ------------------------------------------------------------ | ------------------------------------------------------------ | --------------------- |
| [5. 最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring/)（中） | [解题](Leetcode/Dynamic/5_longest-palindromic-substring)、[C++](Leetcode/Dynamic/5_longest-palindromic-substring/readme.md) | 动态规划✅             |
| [53. 最大子序和](https://leetcode-cn.com/problems/maximum-subarray/) | [解题](Leetcode/Dynamic/53_maximum-subarray)、[C++](Leetcode/Dynamic/53_maximum-subarray/main.cpp)、[Python](Leetcode/Dynamic/53_maximum-subarray/main.py) | 动态规划✔️、分而治之   |
| [55. 跳跃游戏](https://leetcode-cn.com/problems/jump-game/)（中） | [解题](Leetcode/Dynamic/55_jump-game)、[C++](Leetcode/Dynamic/55_jump-game/main.cpp)、[Python](Leetcode/Dynamic/55_jump-game/main.py) | 动态规划（两种思路）✔️ |
| [122. 买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/) | [解题](Leetcode/Dynamic/122_best-time-to-buy-and-sell-stock-ii)、[C++](Leetcode/Dynamic/122_best-time-to-buy-and-sell-stock-ii/main.cpp)、python | 动态规划✔️             |
| [198. 打家劫舍](https://leetcode-cn.com/problems/house-robber/) | [解题](Leetcode/Dynamic/198_house-robber/readme.md)、[C++](Leetcode/Dynamic/198_house-robber/main.cpp)、python | 动态规划✔️             |

## 设计问题

| 题目名称                                                     | 文件位置（解题、源码）                                       | 实现的方法          |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------- |
| [155. 最小栈](https://leetcode-cn.com/problems/min-stack/)   | [解题说明](Leetcode/Design/155_min-stack/155_min-stack.md)、[code](Leetcode/Design/155_min-stack/main.cpp) | 辅助栈✔️             |
| [384. 打乱数组](https://leetcode-cn.com/problems/shuffle-an-array/) | [解题说明](Leetcode/Design/384_shuffle-an-array/384_shuffle-an-array.md)、[code](Leetcode/Design/384_shuffle-an-array/main.cpp) | 随机抽取✔️、洗牌算法 |

## 数学问题

| 题目（难度）                                                 | 文件位置（解题、源码）                                       | 实现的方法                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ | --------------------------------- |
| [13. 罗马数字转整数](https://leetcode-cn.com/problems/roman-to-integer/) | [解题说明](Leetcode/Math/13_roma-to-int/13_roman-to-integer.md)、[C++](Leetcode/Math/13_roma-to-int/main.cpp) | 模拟法✔️                           |
| [204. 计数质数](https://leetcode-cn.com/problems/count-primes/) | 解题说明、[C++](Leetcode/Math/204_count-primes/main.cpp)     | 枚举法✔️、埃氏筛✔️                  |
| [233. 数字 1 的个数](https://leetcode-cn.com/problems/number-of-digit-one/)（中～难） | [解题](Leetcode/Math/233_number-of-digit-one/233_number-of-digit-one.md)、[C++](Leetcode/Math/233_number-of-digit-one/main.cpp)、[Python](Leetcode/Math/233_number-of-digit-one/main.py) | 枚举法✅                           |
| [326. 3的幂](https://leetcode-cn.com/problems/power-of-three/) | [解题说明](Leetcode/Math/326_power-of-three/326_power-of-three.md)、[C++](Leetcode/Math/326_power-of-three/main.cpp) | 三进制✔️、对数公式✔️、利用整数限制✔️ |
| [412. Fizz Buzz](https://leetcode-cn.com/problems/fizz-buzz/) | [code](Leetcode/Math/412_fizz-buzz/main.cpp)                 | 字符串连接✔️                       |

## 其他 

| 题目名称                                                     | 文件位置（解题、源码）                                       | 实现的方法             |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ---------------------- |
| [20. 有效的括号](https://leetcode-cn.com/problems/valid-parentheses/) | [解题说明](Leetcode/Other/20_valid-parentheses/20_valid-parentheses.md)、[c++](Leetcode/Other/20_valid-parentheses/20_valid-parentheses.cpp)、[python](Leetcode/Other/20_valid-parentheses/20_vaild-parentheses.py) | 栈匹配✔️                |
| [190. 颠倒二进制位](https://leetcode-cn.com/problems/reverse-bits/) | [解题说明](Leetcode/Other/190_reverse-bits/190_reverse-bits.md)、[code](Leetcode/Other/190_reverse-bits/main.cpp) | 逐位颠倒✔️、位运算分治  |
| [191. 位1的个数](https://leetcode-cn.com/problems/number-of-1-bits/) | [解题说明](Leetcode/Other/119_number-of-1-bits/119_number-of-1-bits.md)、[code](Leetcode/Other/119_number-of-1-bits/main.cpp) | 循环检查✔️、位运算优化✔️ |
| [缺失数字](https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof/) | [解题说明](Leetcode/Other/xxx_missing-number/xxx_missing-number.md)、[code](Leetcode/Other/xxx_missing-number/main.cpp) | 异或运算✔️              |

## 树

> TreeNode的数据结构在CppUtils和PyUtils的工具包中

| 题目（难度）                                                 | 文件位置（解题、源码）                                       | 实现的方法         |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------ |
| [94. 二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)（易～中） | [C++](Leetcode/Tree/94_binary-tree-inorder-traversal/main.py)、[python](Leetcode/Tree/94_binary-tree-inorder-traversal/main.py) | 递归✅、栈          |
| [98. 验证二叉搜索树](https://leetcode-cn.com/problems/validate-binary-search-tree/) | [解题](Leetcode/Tree/98_validate-binary-search-tree/readme.md)、[C++](Leetcode/Tree/98_validate-binary-search-tree/main.cpp) | 利用性质递归✅      |
| [101. 对称二叉树](https://leetcode-cn.com/problems/symmetric-tree/) | [解题](Leetcode/Tree/101_symmetric-tree/readme.md)、[C++](Leetcode/Tree/101_symmetric-tree/main.cpp) | 利用性质递归✅      |
| [102. 二叉树的层序遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/) | [解题](Leetcode/Tree/102_binary-tree-level-order-traversal/readme.md)、[C++](Leetcode/Tree/102_binary-tree-level-order-traversal/main.cpp) | 队列实现BFS法✅     |
| [103. 二叉树的锯齿形层序遍历](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/)（类似102） | [解题](Leetcode/Tree/103_binary-tree-zigzag-level-order-traversal/readme.md)、[C++](Leetcode/Tree/103_binary-tree-zigzag-level-order-traversal/main.cpp) | 层序遍历✅          |
| [104. 二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/) | [解题](Leetcode/Tree/104_maximum-depth-of-binary-tree/readme.md)、[C++](Leetcode/Tree/104_maximum-depth-of-binary-tree/main.cpp) | 栈实现DFS深度遍历✅ |
| [108. 将有序数组转换为二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/)（中～难） | [解题](Leetcode/Tree/108_convert-sorted-array-to-binary-search-tree/readme.md)、[C++](Leetcode/Tree/108_convert-sorted-array-to-binary-search-tree/main.cpp) | 递归构建✅          |
| [116. 填充每个节点的下一个右侧节点指针](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/)（类似102） | [解题](Leetcode/Tree/116_populating-next-right-pointers-in-each-node/readme.md)、[C++](Leetcode/Tree/116_populating-next-right-pointers-in-each-node/main.cpp)、[python](Leetcode/Tree/116_populating-next-right-pointers-in-each-node/main.py) | 层序遍历✅          |

# 图

| 题目（难度）                                                 | 文件位置（解题、源码）                                       | 实现的方法   |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------ |
| [200. 岛屿数量](https://leetcode-cn.com/problems/number-of-islands/)（中） | [解题](Leetcode/Graph/200_number-of-islands/main.py)、[C++](Leetcode/Graph/200_number-of-islands/main.py)、[python](Leetcode/Graph/200_number-of-islands/main.py) | DFS✅、并查集 |

# 回溯

| 题目（难度）                                                 | 文件位置（解题、源码）                                       | 实现的方法 |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ---------- |
| [17. 电话号码的字母组合](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/)（易～中） | [解题](Leetcode/Backtrace/17_letter-combinations-of-a-phone-number/readme.md)、[C++](Leetcode/Backtrace/17_letter-combinations-of-a-phone-number/main.cpp)、[python](Leetcode/Backtrace/17_letter-combinations-of-a-phone-number/main.py) | 回溯遍历✅  |
| [22. 括号生成](https://leetcode-cn.com/problems/generate-parentheses/)（易～中） | [解题](Leetcode/Backtrace/22_generate-parentheses)、[C++](Leetcode/Backtrace/22_generate-parentheses/main.cpp)、[python](Leetcode/Backtrace/22_generate-parentheses/main.py) | 回溯剪枝✅  |
| [46. 全排列](https://leetcode-cn.com/problems/permutations/)（易～中） | [解题](Leetcode/Backtrace/46_permutations/readme.md)、[C++](Leetcode/Backtrace/46_permutations/main.cpp)、[python](Leetcode/Backtrace/46_permutations/main.py) | 回溯剪枝✅  |
| [79. 单词搜索](https://leetcode-cn.com/problems/word-search/)（中～难） | [解题](Leetcode/Backtrace/79_word-search/reademe.md)、[C++](Leetcode/Backtrace/79_word-search/main.cpp)、[python](Leetcode/Backtrace/79_word-search/main.py) | 回溯剪枝✅  |



# 排列&搜索

| 题目（难度）                                                 | 文件位置（解题、源码）                                       | 实现的方法                   |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ---------------------------- |
| [56. 合并区间](https://leetcode-cn.com/problems/merge-intervals/)（易） | [解题](Leetcode/Sort&Search/56_merge-intervals)、[C++](Leetcode/Sort&Search/56_merge-intervals/main.cpp)、[python](Leetcode/Sort&Search/56_merge-intervals/main.py) | 排序后合并✅                  |
| [75. 颜色分类](https://leetcode-cn.com/problems/sort-colors/)（易） | [解题](Leetcode/Sort&Search/75_sort-colors)、[C++](Leetcode/Sort&Search/75_sort-colors/main.cpp)、[python](Leetcode/Sort&Search/75_sort-colors/main.py) | 双指针✅                      |
| [215. 数组中的第K个最大元素](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/)（中） | [解题](Leetcode/Sort&Search/215_kth-largest-element-in-an-array)、[C++](Leetcode/Sort&Search/215_kth-largest-element-in-an-array/main.cpp)、[python](Leetcode/Sort&Search/215_kth-largest-element-in-an-array/main.py) | 基于快速排序的思想✅、堆排序✅ |
| [347. 前 K 个高频元素](https://leetcode-cn.com/problems/top-k-frequent-elements/)（中） | [解题](Leetcode/Sort&Search/347_top-k-frequent-elements)、[C++](Leetcode/Sort&Search/347_top-k-frequent-elements/main.cpp)、[python](Leetcode/Sort&Search/347_top-k-frequent-elements/main.py) | 堆排序✅                      |



# 贪心

| 题目（难度）                                                 | 文件位置（解题、源码）                                       | 实现的方法 |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ---------- |
| [334. 递增的三元子序列](https://leetcode-cn.com/problems/increasing-triplet-subsequence/)（中） | [解题](Leetcode/Array&String/334_increasing-triplet-subsequence/readme.md)、[C++](Leetcode/Array&String/334_increasing-triplet-subsequence/main.cpp)、[python](Leetcode/Array&String/334_increasing-triplet-subsequence/main.py) | 辅助数组✅  |

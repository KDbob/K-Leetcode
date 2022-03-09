#### [17. 电话号码的字母组合](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/)

> #递归 #回溯 #排列组合

给定一个仅包含数字 `2-9` 的字符串，返回所有它能表示的字母组合。答案可以按 **任意顺序** 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

![img](readme.assets/200px-telephone-keypad2svg.png)

 

**示例 1：**

```
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

**示例 2：**

```
输入：digits = ""
输出：[]
```

**示例 3：**

```
输入：digits = "2"
输出：["a","b","c"]
```

# 解题

## 方法一：回溯法

### 1. 思路

排列组合问题，利用回溯法的思想，解空间可以用一颗完全n叉树来表示（n=digits.length）


### 2 编程

#### 2.1 数据结构

- `unordered_map<char, string> phoneMap`：一个map用于保存按键到字符串的映射

- `int index`（**递归关键变量**)：可以看作是递归的深度

  > 例如digits = "23"，index只会取0、1，递归深度是2

- `vector<string> combinations`：用于存储最后组合的结果

- `string combination;`：临时存储：存储一次递归深度的结果

#### 2.2 算法流程

0. 初始化按键的映射

1. 执行递归函数（从0开始）

   > 递归没有出口，会完整地遍历完解空间的n叉树

   - 一个完整深度遍历的结束条件：index = digits.length时
     - 将临时字符串数组中的值加入到combinations

   - 遍历这个深度的数量，执行递归（index+1）
     - 保存到临时字符串数组中combination

2. 返回combinations

#### 2.3 代码实现

```c++
vector<string> letterCombinations(string digits) {
    unordered_map<char, string> phoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
    };
    vector<string> combinations;
    string combination;
    backtrack(phoneMap, digits, 0, combination, combinations);
    return combinations;
}

void backtrack(const unordered_map<char, string>& phoneMap, const string& digits,int index, string& combination, vector<string>& combinations) {
    if (index == digits.length()) {
        combinations.push_back(combination);
    } else {
        char num = digits[index];
        const string& letters = phoneMap.at(num);
        for (auto letter:letters) {
            combination.push_back(letter);
            backtrack(phoneMap, digits, index + 1, combination, combinations);
            combination.pop_back(); // ★临时的string容器需要清空
        }
    }
}
```



### 3 复杂度分析

​	// TODO



# 总结

- C++中递归用了很多引用的变量，Python中仅需使用递归关键变量

- 在递归中用要的临时容器的思想，在一个深度的递归后清空后可以重复利用该变量

  ```c++
  void backtrack(...) {
  		for (auto letter:letters) {
              combination.push_back(letter);
              backtrack(...);
              combination.pop_back(); // ★临时的string容器需要清空
          }
  ```

  


#### [14. 最长公共前缀](https://leetcode-cn.com/problems/longest-common-prefix/)

编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 `""`

示例 1：

```
输入：strs = ["flower","flow","flight"]
输出："fl"
```


示例 2：

```
输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。
```


提示：

0 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] 仅由小写英文字母组成

# 解题思路

## 方法一：横向扫描（TODO）

## 方法二：纵向扫描

从前往后遍历所有字符串的每一列，比较相同列上的字符是否相同，如果相同则继续对下一列进行比较。

### 算法流程

0. 选取数组中strs[0]作为外循环的字符串

1. 外循环：指针i遍历字符串的长度，str[0].length
   - 取str[0]的每个字符作为对比的公共字符
2. 内循环：指针j遍历每组的字符串的第i个字符：`strs[j][i]`。比较和`strs[0][i]`的差异
   - 相同：继续遍历下一个字符
   - 不同：说明`strs[0][0~i]`是最长公共前缀

#### 代码实现

```c++
string longestCommonPrefix(vector<string>& strs) {
        string fir_str = strs[0];
        int fir_len = strs[0].length();
        for (int i = 0; i < fir_str.length(); ++i) {
            char ch = fir_str[i];
            for (int j = 1; j < strs.size(); ++j) {
                string str = strs[j];
                if (str.length() <= fir_len && ch == str[i]) {

                } else {
                    return fir_str.substr(0, i);
                }
            }
        }
        return fir_str;
    }
```

## 方法三：分而治之（TODO）

# 知识点总结

- C++中的`substr(pos, n)`函数

  ```c++
  // C++中获取子串，是0～i-1的字符串。
  // 即从pos开始，数n个字符。
  fir_str.substr(0, i)
  ```

- 逻辑表达式简写

  ```c++
  // 改写前
if (str.length() <= fir_len && ch == str[i]) {
  
  } else {
    return fir_str.substr(0, i);
  }
  // 取反即可
  if (str.length() != fir_len || ch != str[i]) {// 由于是在循环体中，str.length() > fir_len 可以用!=来代替
  
  } else {
    return fir_str.substr(0, i);
  }
  
  
  ```


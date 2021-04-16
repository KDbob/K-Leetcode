#### [125. 验证回文串](https://leetcode-cn.com/problems/valid-palindrome/)

给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

```
输入: "A man, a plan, a canal: Panama"
输出: true
```


示例 2:

```
输入: "race a car"
输出: false
```

# 解题思路

可以先对字符串做预处理：即保留字母和数字字符。保存预处理后的字符串为sgood

然后判断sgood是否是回文串：

判断方法有两种

1. 用语言自带的串API：sgood如果翻转后==自身，说明是回文串。
2. 使用双指针，分别指向sgood的左端和右端，一一对比两个指针指向的字符。如果最后指针相遇，说明是回文串。

### 准备数据结构

string sgood;

用于存储预处理后的字符串

### 算法流程

0. 对字符串做预处理，即遍历同时将数字与字符(以小写方式存储)保存在sgood中

1. 判断sgood是否是回文串（双指针法）

   - 使用双指针，分别指向左右两端

     > sgood[left++]==sgood[right--]，当两个指针相遇时，说明是回文串

   - 值判断不等时，返回false

### 代码实现

```c++
bool isPalindrome(string s) {
    string sgood;
    for (auto ch:s) {
        if (isalnum(ch)) {
            sgood += tolower(ch);
        }
    }
    int l = 0, r = sgood.size()-1;
    while (l < r) {
        if (sgood[l++] != sgood[r--] ) return false;
    }
    return true;
}
```

### 复杂度分析

时间复杂度：$O(n)$

> 需要遍历一次原字符串，双指针遍历1/2次sgood字符串

空间复杂度：$O(n)$

> 最长需要一个n长度的sgood字符串作为

##### 算法改进

可以直接对原字符串直接判断，这空间复杂度为$O(1)$

# 知识点总结

- C++>String > std::isalnum

  Checks if the given character is an alphanumeric character as classified by the current C locale. In the default locale, the following characters are alphanumeric:

  判断字符是否是字母和数字类型，这些是字母数字类型：

  - digits (`0123456789`)
  - uppercase letters (`ABCDEFGHIJKLMNOPQRSTUVWXYZ`)
  - lowercase letters (`abcdefghijklmnopqrstuvwxyz`)

- ```c++
  tolower() // 存储为小写字母
  ```

- 循环条件的写法

  ```C++
  while (l < r) {
  	if (sgood[l++] != sgood[r--] ) return false;
  }
  // 这种写法可能出现循环的overflowed，需要避免
  while (l != r) {
  	if (sgood[l++] != sgood[r--] ) return false;
  }
  ```

  


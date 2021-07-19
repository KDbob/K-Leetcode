#### [242. 有效的字母异位词](https://leetcode-cn.com/problems/valid-anagram/)

给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

示例 1:

```
输入: s = "anagram", t = "nagaram"
输出: true
```


示例 2:

```
输入: s = "rat", t = "car"
输出: false
```


说明:
你可以假设字符串只包含小写字母。

进阶:
如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

# 解题思路

## 方法一：使用hash表

#### 基本思想

- 首先遍历str1，统计str1中的字符出现频率到mp
- 然后遍历str2，将str2中的字符出现频次--
  - 如果出现-1的情况，说明不是有效的异位词

#### 准备数据结构

hashmap<char, int> mp;

> 用于统计字符串中字符出现的次数

#### 算法流程

0. 判断字符串长度是否相同
1. 遍历首先遍历str1，统计str1中的字符出现频率到mp
2. 然后遍历str2，将str2中的字符出现频次
   - 如果出现-1的情况，说明不是有效的异位词

```c++
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    vector<int> mp(26, 0);
    for(auto ch:s) {
        mp[ch - 'a']++;
    }
    for(auto ch:t) {
        mp[ch - 'a']--;
        if (mp[ch - 'a'] < 0) {
            return false;
        }
    }
    return true;
}
```

# 知识点总结

}Unicode 是为了解决传统字符编码的局限性而产生的方案，它为每个语言中的字符规定了一个唯一的二进制编码。而Unicode 中可能存在一个字符对应多个字节的问题，

- 为了让计算机知道多少字节表示一个字符，面向传输的编码方式的UTF−8 和UTF−16 也随之诞生逐渐广泛使用

进阶问题的核心点在于「字符是离散未知的」，因此我们用哈希表维护对应字符的频次即可。同时读者需要注意 Unicode 一个字符可能对应多个字节的问题，**不同语言对于字符串读取处理的方式是不同的**


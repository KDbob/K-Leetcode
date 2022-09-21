#### [面试题 08.08. 有重复字符串的排列组合](https://leetcode.cn/problems/permutation-ii-lcci/)

> #回溯 #去重剪枝

有重复字符串的排列组合。编写一种方法，计算某字符串的所有排列组合。

**示例1:**

```
 输入：S = "qqe"
 输出：["eqq","qeq","qqe"]
```

**示例2:**

```
 输入：S = "ab"
 输出：["ab", "ba"]
```

**提示:**

1. 字符都是英文字母。
2. 字符串长度在[1, 9]之间



# 总结

1. 使用set作为局部变量放在函数中的意义

   ```python
   def backtrace(idx):
     seen = set()  # set作为局部变量的原因是，在这层(idx)不能选择重复的字母
     if idx == n:
       res.append("".join([S[i] for i in chosen]))
       else:
         for i in range(n):
           if i not in chosen and S[i] not in seen:
             chosen.append(i)
             backtrace(idx + 1)
             chosen.pop()
             seen.add(S[i])
   ```

   - 对**每一层**的枚举起到去重的作用
#### [204. 计数质数](https://leetcode-cn.com/problems/count-primes/)

统计所有小于非负整数 *`n`* 的质数的数量。

 

**示例 1：**

```
输入：n = 10
输出：4
解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
```

**示例 2：**

```
输入：n = 0
输出：0
```

**示例 3：**

```
输入：n = 1
输出：0
```

 

**提示：**

- `0 <= n <= 5 * 106`

# 解题思路

## 方法一：枚举

> 判断一个数n是否是质数的常见方法就是判断它能不能被$2\to\sqrt{n}$整除

### 准备数据结构

`int sum=0; //用于统计一共多少个质数`

### 算法流程

`bool isPrime(int num)；`

> 定义一个方法，该方法判断是否是质数

1. 遍历1～n
   - 如果i是质数，则统计

2. 返回sum

### 代码实现

```c++
bool isPrime(int num) {
    for (int i=2; i * i <=num; i++) {
      // 程序隐含了：2和3本身是质数，但是不满足<sqrt(i),所以不会进入循环体内
        if (num % i==0) return false;
    }
    return true;
}

int countPrimes(int n) {
    int sum = 0;
    for (int i = 2; i < n; ++i) {
        if (isPrime(i)){
            sum++;
        }
    }
    return sum;
}
```

### 复杂分析

空间复杂度：$O(1)$

时间复杂度：$O(n·\sqrt{n})$



## 方法二：埃氏筛

> 该算法由希腊数学家厄拉多塞（\rm EratosthenesEratosthenes）提出，称为厄拉多塞筛法，简称埃氏筛

有一个事实：如果一个数是质数记为x，那么这个数的倍数：2x，3x一定不是质数

因此我们可以用一个数组用来标记是否为质数。

- 我们知道最小的质数是2，那么2的倍数4、6、8...可以标记成非质数

- 我们从 2x 开始标记其实是冗余的，应该直接从 x⋅x 开始标记，因为 2x,3x这些数一定在 x之前就被其他数的倍数标记过了：例如 2 的所有倍数，3 的所有倍数等。

### 准备数据结构

`vector<bool> isPrimeArr(n, true); `

> 数组长度取n，用于标记自然数是否是质数，初始全设为true

`int sum=0; //用于统计一共多少个质数`

### 算法流程

0. 初始状态设isPrime全为true，即默认都是质数（0、1除外）。

1. 遍历2～n，i作为内层循环（标记）的基数

   - 如果i是质数，统计，并开始标记i的倍数：

     i平方开始标记，i的倍数(2i、3i...)，一直到n，标记为false

2. 统计isPrime中为true的个数（在遍历的过程中统计）

### 代码实现

```C++
int countPrimes2(int n) {
    vector<bool> isPrimeArr(n, true);
    int sum = 0;
    for (int i = 2; i < n; ++i) {
        if (isPrimeArr[i]) {
            sum++;
            if ((long long) i * i < n) {
                for (int j = i * i; j < n; j += i) {
                    isPrimeArr[j] = false;
                }
            }
        }
    }
    return sum;
}
```

- 前面的质数先统计，因此不会被标记为非质数，因此不会产生冲突
- 只需要将质数的倍数标记为非质数

### 复杂度分析

时间复杂度：$O(n·\log{n}·\log{n})$

空间复杂度：$O(n·\log{n})$


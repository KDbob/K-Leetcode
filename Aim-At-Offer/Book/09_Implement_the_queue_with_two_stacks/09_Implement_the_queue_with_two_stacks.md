#### [剑指 Offer 09. 用两个栈实现队列](https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/)

用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

```c++
输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
```

> 示例解释：
>
> 输入的两个数组是一一对照的，要同时看：
>
> 表示一系列的操作：创建队列、删除头、尾部插入5、尾部插入2、删除头、删除头。
>
> 输出表示每一步的输出结果：

# 解题思路

队列的特性是先进先出，栈的特性是先进后出

如果将两个栈的操作连贯起来，得到的效果就是队列。具体操作如下:

两个栈分别设为stack1和stack2

> stack1用于插入数据，stack2用于删除数据

1. 插入数据时，压入stack1
2. 删除数据时，从stack2中弹出数据
   - 先检查stack2中是否有数据，有则弹出
   - 如果stack2中无数据，先将stack1中的数据一个个压入stack2中

# 知识点总结

1. #### 条件判断语句可以重构，使得代码更简洁。

```c++
int deleteHead() {
    if (!deleteStack.empty()) {         // 1.如果deleteStack中有数据，直接pop
        int result = deleteStack.top();		// **重复语句
        deleteStack.pop();								// **
        return result;										// **
    } else if (!appendStack.empty()) {  // 2.如果deleteStack中无数据，先将appendStack中的元素压到deleteStack中，再pop
        while (!appendStack.empty()) {
            int temp = appendStack.top();	
            appendStack.pop();						
            deleteStack.push(temp);
        }
        int result = deleteStack.top();		// **重复语句
        deleteStack.pop();								// **
        return result;										// **
    } else {
        return -1;
    }
}
```

重构代码：

```c++
int deleteHead_consice() {
    if (!appendStack.empty()) {  // 2.如果deleteStack中无数据，先将appendStack中的元素压到deleteStack中，再pop
        while (!appendStack.empty()) {
            int temp = appendStack.top();	
            appendStack.pop();
            deleteStack.push(temp);
        }
    }
    if (!deleteStack.empty()) {         // 1.如果deleteStack中有数据，直接pop
        int result = deleteStack.top();		// **将处理提前，消除了重复语句
        deleteStack.pop();								// **
        return result;										// **
    } else {
        return -1;
    }
}
```

2. #### 数据结构stack的堆栈操作：

   - top()：返回一个栈顶元素的引用，类型为 T&。如果栈为空，返回值未定义。
   - push(const T& obj)：可以将对象副本压入栈顶。这是通过调用底层容器的 push_back() 函数完成的。
   - push(T&& obj)：以移动对象的方式将对象压入栈顶。这是通过调用底层容器的有右值引用参数的 push_back() 函数完成的。
   - pop()：弹出栈顶元素。
   - size()：返回栈中元素的个数。
   - empty()：在栈中没有元素的情况下返回 true。


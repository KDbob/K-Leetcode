#### [341. 扁平化嵌套列表迭代器](https://leetcode-cn.com/problems/flatten-nested-list-iterator/)

给你一个嵌套的整型列表。请你设计一个迭代器，使其能够遍历这个整型列表中的所有整数。

列表中的每一项或者为一个整数，或者是另一个列表。其中列表的元素也可能是整数或是其他列表。

```
输入: [[1,1],2,[1,1]]
输出: [1,1,2,1,1]
```


解释: 通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是: [1,1,2,1,1]。
示例 2:

```
输入: [1,[4,[6]]]
输出: [1,4,6]
```


解释: 通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是: [1,4,6]。

# 解题思路

可以将NestInteger看作是一颗树

- 叶子结点是integer值
- 非叶子结点是NestInteger类型

```tex
	[[1, 1], 2, [1, 1]]
			/   |    \
	[1, 1]  2   [1, 1]
	/ \						/ \
	1 1					  1 1
```

# 知识点总结

- Java中形参前面三个点的含义

  > 表示的是可变参数，即表示的传入的参数个数是可变。传入多少个参数都被放到一个数组里面。

  ```java
      public NestedList(NestedInteger ...values){
          for(NestedInteger value : values){
              li.add(value);
          }
      }
  ```

- 使用vector中的迭代器

  ```c++
  //方法二，使用迭代器将容器中数据输出 
  vector<int>::iterator it;//声明一个迭代器，来访问vector容器，作用：遍历或者指向vector容器的元素 
  for(it=obj.begin();it!=obj.end();it++){
          cout<<*it<<" ";
  }
  ```

- 嵌套类的实现与构建

  ```c++
  class NestedInteger {
  private:
      int val;
      vector<NestedInteger> list;
      bool integerFlag = true;
  public:
      NestedInteger(int v){
          this->val = v;
          this->integerFlag = true;
      }
  
      NestedInteger(vector<NestedInteger> li) {
          this->list = li;
          this->integerFlag = false;
      }
      bool isInteger() {
          return this->integerFlag;
      }
  
      int getInteger() {
          return this->val;
      }
  
      vector <NestedInteger> &getList() {
          return this->list;
      }
  };
  ```

  ```c++
  vector<NestedInteger> v1 = {NestedInteger(1), NestedInteger(1)};
  NestedInteger n1 = NestedInteger(v1);
  NestedInteger n2 = NestedInteger(v1);
  vector<NestedInteger> v = {n1, NestedInteger(2), n2};
  ```

  


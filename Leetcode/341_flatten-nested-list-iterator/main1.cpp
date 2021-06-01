// 341. 扁平化嵌套列表迭代器
// Created by kaide on 2021/3/25.
//
#include <iostream>
#include <vector>

using namespace std;

class NestedInteger {
public:
    NestedInteger(){};
    virtual bool isInteger() const = 0;

    virtual int getInteger() const = 0;

    virtual const vector <NestedInteger *> &getList() const = 0;
    virtual ~NestedInteger(){};
};

class SingletonInteger: public NestedInteger {
private:
    int value;
    vector<NestedInteger *> list;
public:
    SingletonInteger(int v){
        this->value = v;
    }

    bool isInteger() const override {
        return false;
    }

    int getInteger() const override {
        return this->value;
    }

    const vector<NestedInteger *> &getList() const override {
        return list;
    }

};


class NestedList: public NestedInteger {
private:
    vector<NestedInteger *> list;
public:
    NestedList(vector<NestedInteger *> values){
        for (NestedInteger * v:values) {
            list.push_back(v);
        }
    }

    bool isInteger() const override {
        return false;
    }

    int getInteger() const override {
        return 0;
    }

    const vector<NestedInteger *> &getList() const override {
        return this->list;
    }

};

class NestedIterator {
private:
    vector<int> vals;
    vector<int>::iterator cur;

    void dfs(const vector<NestedInteger> &nestedList) {
        for (auto &nest : nestedList) {
            if (nest.isInteger()) {
                vals.push_back(nest.getInteger());
            } else {
                dfs(nest.getList());
            }
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
        cur = vals.begin();
    }

    int next() {
        return *cur++;
    }

    bool hasNext() {
        return cur != vals.end();
    }
};




int main() {
    SingletonInteger *s1 = new SingletonInteger(1);
    SingletonInteger *s2 = new SingletonInteger(1);
    vector<NestedInteger *> v1 = {s1, s2};
    NestedList *l1 = new NestedList(v1);
    SingletonInteger *s3 = new SingletonInteger(1);
    SingletonInteger *s4 = new SingletonInteger(1);
    vector<NestedInteger *> v2 = {s3, s4};
    NestedList *l2 = new NestedList(v2);
    SingletonInteger *s5 = new SingletonInteger(2);
    vector<NestedInteger *> v = {l1, s5, l2};

    NestedList p = NestedList(v);
//    vector<NestedInteger *> p = li.getList();
    cout << p.getList().size();
}
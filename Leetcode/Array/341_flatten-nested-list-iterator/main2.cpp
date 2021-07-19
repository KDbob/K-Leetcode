// 341. 扁平化嵌套列表迭代器
// Created by kaide on 2021/3/25.
//
#include <iostream>
#include <vector>

using namespace std;

class NestedInteger {
public:
    bool isInteger() const;

    int getInteger() const;

    const vector<NestedInteger> &getList() const;
};

class SingletonInteger : public NestedInteger {
private:
    int value;
    vector<NestedInteger> list;
public:
    SingletonInteger(int v) {
        this->value = v;
    }

    bool isInteger() const {
        return true;
    }

    int getInteger() const {
        return this->value;
    }

    const vector<NestedInteger> &getList() const {
        return list;
    }
};


class NestedList : public NestedInteger {
private:
    int value;
    vector<NestedInteger> list;
public:
    NestedList(vector<NestedInteger> values) {
        for (NestedInteger v:values) {
            this->list.push_back(v);
        }
    }

    bool isInteger() const {
        return false;
    }

    int getInteger() const {
        return value;
    }

    const vector<NestedInteger> &getList() const {
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
    vector<NestedInteger> v1 = {SingletonInteger(1), SingletonInteger(1)};
    NestedList li1 = NestedList(v1);
    vector<NestedInteger> v2 = {SingletonInteger(1), SingletonInteger(1)};
    NestedList li2 = NestedList(v2);
    vector<NestedInteger> v = {li1, SingletonInteger(3), li2};
    NestedList *li = new NestedList(v);
//    cout << li.getList().size();
//    NestedIterator i = NestedIterator(reinterpret_cast<vector<struct NestedInteger> &>(li));
//    while (i.hasNext()) cout << i.next();
    return 0;
}
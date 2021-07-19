//
// Created by kaide on 2021/3/28.
//
#include <vector>
#include <iostream>

using namespace std;

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

class NestedIterator {
private:
    vector<int> vals;
    vector<int>::iterator cur;
    void dfs(vector<NestedInteger> &nestedList){
        for (NestedInteger &nest:nestedList) {
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
    vector<NestedInteger> v1 = {NestedInteger(1), NestedInteger(1)};
    NestedInteger n1 = NestedInteger(v1);
    NestedInteger n2 = NestedInteger(v1);
    vector<NestedInteger> v = {n1, NestedInteger(2), n2};

    NestedIterator i(v);
    while (i.hasNext()) {
        cout << i.next();   // expect: 11211
    }

}
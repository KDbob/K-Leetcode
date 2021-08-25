// 剑指 Offer 09. 用两个栈实现队列
// Created by kaide on 2021/3/21.
//
#include <stack>

using namespace std;

class CQueue {
    stack<int> appendStack, deleteStack;
public:
    CQueue() {  // 初始化的作用：将两个栈中的元素都清空
        while (!appendStack.empty()) {
            appendStack.pop();
        }
        while (!deleteStack.empty()) {
            deleteStack.pop();
        }
    }

    /**
     * 在尾部插入元素
     * @param value 要插入的数据
     */
    void appendTail(int value) {
        appendStack.push(value);
    }

    /**
     * 删除头元素
     * @return 删除的数据值，如果为空输出-1
     */
    int deleteHead() {
        if (!deleteStack.empty()) {         // 1.如果deleteStack中有数据，直接pop
            int result = deleteStack.top();
            deleteStack.pop();
            return result;
        } else if (!appendStack.empty()) {  // 2.如果deleteStack中无数据，先将appendStack中的元素压到deleteStack中，再pop
            while (!appendStack.empty()) {
                int temp = appendStack.top();
                appendStack.pop();
                deleteStack.push(temp);
            }
            int result = deleteStack.top();
            deleteStack.pop();
            return result;
        } else {
            return -1;
        }
    }

    /*
     * 同上：只是优化逻辑，显得更加简洁
     */
    int deleteHead_consice() {
        if (!appendStack.empty()) {  // 2.如果deleteStack中无数据，先将appendStack中的元素压到deleteStack中，再pop
            while (!appendStack.empty()) {
                int temp = appendStack.top();
                appendStack.pop();
                deleteStack.push(temp);
            }
        }
        if (!deleteStack.empty()) {         // 1.如果deleteStack中有数据，直接pop
            int result = deleteStack.top();
            deleteStack.pop();
            return result;
        } else {
            return -1;
        }
    }


};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

int main() {
    CQueue *obj = new CQueue();
    obj->appendTail(3);
    int param_2 = obj->deleteHead();
    printf("%d\n", param_2); // expect:3
    int param_3 = obj->deleteHead_consice();
    printf("%d\n", param_3); // expect:-1
}
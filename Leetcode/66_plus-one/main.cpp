// 66. 加一
// Created by kaide on 2021/4/3.
//
#include <vector>

using namespace std;


/**
 * 给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一
 * @param digits 数组：数组中每个元素只存储单个数字
 * @return：在该数基础上+1的数组
 */
vector<int> plusOne(vector<int> &digits) {
    int indx = digits.size() - 1;
    bool carry;
    do {
        carry = false;
        if (indx == -1) {
            digits.insert(digits.begin(), 1);
            break;
        }
        if (digits[indx] == 9) {
            digits[indx] = 0;
            carry = true;
            indx --;
        } else {
            digits[indx] +=1;
        }
    } while (carry);
    return digits;
}

/* verbose original code
 * 冗长原始代码:
vector<int> plusOne_original(vector<int> &digits) {
    int indx = digits.size() - 1;
    bool carry ;
    if (digits[indx] == 9) {  // 最低位是9，说明要进位
        carry = true;
        digits[indx] = 0;
        indx --;
        while (carry) {
            carry = false;
            if (indx == -1) {
                digits.insert(digits.begin(), 1);
                break;
            }
            if (digits[indx] == 9) {
                digits[indx] = 0;
                carry = true;
                indx --;
            } else {
                digits[indx] +=1;
            }
        }
    } else {
        digits[indx] += 1;
    }
    return digits;
}*/


int main() {
    vector<int> digits = {9, 9, 9};
    vector<int> ret = plusOne(digits);
    for (auto num:digits) {
        printf("%d,", num);     //expect: 1, 0, 0, 0
    }
}
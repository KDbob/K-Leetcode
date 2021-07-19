//
// Created by kaide on 2021/5/30.
//
#include <vector>
#include <string>

using namespace std;

vector<string> fizzBuzz(int n) {
    vector<string> res;
    for (int i = 1; i <= n; ++i) {
        string str = "";
        if (i % 3 == 0) {
            str.append("Fizz");
        }
        if (i % 5 == 0) {
            str.append("Buzz");
        }
        if (str == "") {
            str.append(to_string(i));
        }
        res.push_back(str);
    }
    return res;
}

int main() {
    vector<string> res = fizzBuzz(15);
    for (auto r:res) {
        printf("%s\n", r.c_str());
    }
}
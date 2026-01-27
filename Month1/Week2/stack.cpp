#include <iostream>
#include <vector>
using namespace std;

class Stack {
private:
    vector<int> v;

public:
    void push(int x) {
        v.push_back(x);
    }

    int pop() {
        if (v.empty()) return -1;
        int val = v.back();
        v.pop_back();
        return val;
    }

    int top() {
        return v.empty() ? -1 : v.back();
    }

    bool empty() {
        return v.empty();
    }
};

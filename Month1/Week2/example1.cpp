#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    stack<int> st;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        if (c == 'C') {
            st.push(12);
        } else if (c == 'H') {
            st.push(1);
        } else if (c == 'O') {
            st.push(16);
        } else if (c == '(') {
            st.push(-5);
        } else if (c == ')') {
            int summ = 0;
            while (st.top() != -5) {
                summ += st.top();
                st.pop();
            }
            st.pop();
            st.push(summ);
        } else {
            int num = c - '0';
            int x = st.top(); 
            st.pop();
            st.push(x * num);
        }
    }

    int result = 0;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    cout << result;
}
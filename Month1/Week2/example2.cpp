#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    stack<int> st;  
    vector<int> res(n);

    for (int i = 0; i < n; i++) {
        int c = arr[i];
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        if (st.empty()) {
            res[i] = 0;
        } else {
            res[i] = st.top() + 1;
        }

        st.push(i);
    }

    for (int i = 0; i < n; i++) cout << res[i] << " ";

}
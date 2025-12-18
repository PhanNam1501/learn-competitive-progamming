#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;  
        stack<int> st;  
        int check = 1;


        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            if (a[i] != check) {
                while (!st.empty() && st.top() == check) {
                    st.pop();
                    check += 1;
                }
                st.push(a[i]);
            } else if (a[i] == check) {
                
                check += 1;
            }
        }

        while (!st.empty() && st.top() == check) {
            st.pop();
            check++;
        }

        if (check == n + 1) cout << "yes\n";
        else cout << "no\n";

    } 
}
#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &a, int n) {
    stack<int> st;
    int count = 1;
    int index = 0;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = i + 1;
    }

    while (count <= n) {
        st.push(count);
        while(!st.empty() && st.top() == a[index]) {
            st.pop();
            index++;
        }
        count += 1;
    }
    // while (!st.empty() && st.top() == a[index]) {
    //     st.pop();
    //     index++;
    // }


    if (index == n) return true;
    else return false;
   
}

int main() {
    while (true) {
        int N;
        cin >> N;
        if (N == 0) break; 

        while (true) {
            vector<int> a(N);
            cin >> a[0];
            if (a[0] == 0) break; 

            for (int i = 1; i < N; i++) {
                cin >> a[i];
            }

            if (check(a, N)) cout << "Yes\n";
            else cout << "No\n";
        }

        cout << "\n";
    }

    return 0;
}

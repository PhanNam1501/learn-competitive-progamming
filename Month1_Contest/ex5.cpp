#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;              

    while (T--) {
        int N;
        cin >> N;          

        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];   
        }

        vector<int> L(N), R(N);
        stack<int> st;

        for (int i = 0; i < N; i++) {
            while (!st.empty() && a[i] <= a[st.top()]) st.pop();
            L[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = N - 1; i >= 0; i--) {
            while (!st.empty() && a[i] <= a[st.top()]) st.pop();
            R[i] = st.empty() ? N : st.top();
            st.push(i);
        }

        long long maxx = 0;
        int l_max = 1;
        int r_max = 1;

        for (int i = 0; i < N; i++) {
            long long w = R[i] - L[i] - 1;
            long long r = a[i];
            int cur_l = 0;
            if (L[i] == -1) {
                cur_l = 1;
            } else {
                cur_l = L[i] + 2;
            }

            int cur_r = 0;
            if (R[i] == N) {
                cur_r = N;
            } else {
                cur_r = R[i];
            }

            if (maxx < w * r || (maxx == w * r && cur_l < l_max)) {
                maxx = w * r;
                l_max = cur_l;
                r_max = cur_r;   
            }
        }
        cout << maxx << " " << l_max << " " << r_max << "\n";
    }

    return 0;
}

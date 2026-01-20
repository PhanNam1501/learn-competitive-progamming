#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

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

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        long long width = R[i] - L[i] - 1;
        if (width >= a[i]) {
            long long side = min(width, a[i]);
            ans = max(ans, side);
        }

    }

    cout << ans << '\n';
    return 0;
}

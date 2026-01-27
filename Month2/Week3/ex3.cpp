#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    int maxA = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxA = max(maxA, a[i]);
    }


    vector<long long> cnt(maxA + 1, 0);
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }

    vector<long long> pre(maxA + 1, 0);
    for (int i = 1; i <= maxA; i++) {
        pre[i] = pre[i-1] + cnt[i];
    }
    
    long long ans = 0;

    for (int d = 1; d <= maxA; d++) {
        if (cnt[d] != 0) {
            long long cur = 0;
            for (int k = d; k <= maxA; k+=d) {
                int r =  min(maxA, k + d - 1);
                long long count_in_range = pre[r] - pre[k - 1];
                cur += count_in_range * k;
            }
            ans = max(ans, cur);
        }
    }

    cout << ans << "\n";
    return 0;
}

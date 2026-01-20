#include <bits/stdc++.h>
using namespace std;

int msb(int x) {
    return 31 - __builtin_clz(x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    

    while (t--) {
        int n;
        cin >> n;

        vector<long long> cnt(31, 0);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[msb(x)]++;
        }

        long long ans = 0;
        for (int i = 0; i < 31; i++) {
            long long c = cnt[i];
            ans += c * (c-1) / 2;
        }

        cout << ans << "\n";

        
    }
}

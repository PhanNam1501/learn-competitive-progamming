#include <bits/stdc++.h>
using namespace std;


long long count(vector<int> &a, int h) {
    long long res = 0;
    for (int i = 0; i < a.size(); i++) {
        int w = a[i] < h ? h - a[i] : 0;
        res += w;
    }

    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        long long x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            int y;
            cin >> y;
            a[i] = y;
        }

        long long l = 0;
        long long h = 2e9;
        long long ans = -1;

        while(l <= h) {
            long long m = (l+h)/2;

            if (count(a, m) <= x) {
                ans = m;
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

        cout << ans << "\n";

    }    
   return 0;
}

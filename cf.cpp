#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        int k;
        long long q;
        cin >> n >> k >> q;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            a[i] = x;
        }

        int l = 0;
        long long res = 0;
        for (int i = 0; i < n; i++) {
            if ((a[i] > q)) {
                int dis = i-l;
                if (dis >= k) {
                    for (int j = k; j <= dis; j++) {
                        res += (dis - j + 1);
                    }
                    
                } 
                l=i+1;
            }
        }

        if (a[n-1] <= q) {
            int dis = n-l;
            if (dis >= k) {
                for (int j = k; j <= dis; j++) {
                    res += (dis - j + 1);
                }
                    // res += (((dis * dis) + dis) / 2);
                // l = i;
            }
        }


        cout << res << "\n";

    }
    return 0;
}

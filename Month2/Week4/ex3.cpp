#include <bits/stdc++.h>
using namespace std;

int count(vector<long long> &a, long long d) {
    int res = 1;
    long long x = a[0];
    for (int i = 1; i < a.size(); i++) {
        if ((a[i] - x) >= d) {
            res++;
            x = a[i];
        }
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
        int c;
        cin >> n >> c;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            a[i] = x;
        }

        sort(a.begin(), a.end());

        int l = 1;
        int h = a[n-1] - a[0];
        int x = 0;
        while (l <= h) {
            int m = (l+h)/2;
            if (count(a,m) < c) {
                h = m - 1;
            } else {
                x = m;
                l = m + 1;
            }
        }

        cout << x << "\n";


    }

    return 0;
}

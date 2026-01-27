#include <bits/stdc++.h>
using namespace std;

long long get(vector<long long> &a, long long k) {
    int l = 0;
    int h = a.size() - 1;
    int x = h;
    if (k <= a[0]) x = 0;
    else if (k >= a[h]) x = h;
    else {
        while (l <= h) {
            int m = (l + h) / 2;

            if ((m > 0) && ((a[m] >= k) && (a[m-1] < k))) {
                x = m;
                break;
            }

            if (a[m] < k) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
    }

    long long res = 0;

    if (x == a.size() - 1) {
        return 0;
    } else {
        for (int i = x; i < a.size(); i++) {
            res += (a[i] - k);
        }
        return res;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    long long M;
    cin >> n >> M;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        a[i] = x;
    }

    sort(a.begin(), a.end());
    long long end = a[a.size()-1];
    long long start = 0;

    // int c = get(a, 15);
    // cout << c;
    long long ans = 0;

    while(start <= end) {
        long long m = (end + start) / 2;
        long long k = get(a, m);

        if (k < M) {
            end = m - 1;
        } else {
            ans = m;
            start = m + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}

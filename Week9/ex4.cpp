#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long q;
    long long x;
    cin >> q >> x;

    vector<long long> a(q);
    for (int i = 0; i < q; i++) {
        long long y;
        cin >> y;
        a[i] = y;
    }


    vector<long long> cnt(q, -1);
    vector<long long> res(x * q, -1);
    long long l = 0;
    for (int i = 0; i < q; i++) {
        long long t = a[i] % x;
        long long c = 0;
        if (cnt[t] == -1) {
            cnt[t] = t;
            res[t] = 1;
        } else {
            cnt[t] += x;
            res[cnt[t]]=1;
        }

        for (long long j = l; j < x * q; j++) {
            if (res[j] == -1) {
                cout << j << "\n";
                l = j;
                break;
            }
        }  
    }




    return 0;
}



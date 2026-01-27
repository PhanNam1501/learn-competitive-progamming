#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long t;
    cin >> n >> t;  
    vector<long long> a(n);           
    for (int i = 0; i < n; i++) {
        long long x;
        cin>>x;
        a[i]=x;
    }

    int l = 0;
    int r = 0;
    long long maxx = 0;
    int cnt = 0;
    int res = 0;

    for (int i = 0; i < n; i++) {
        maxx+=a[r];
        cnt++;
        while(maxx > t) {
            maxx-=a[l];
            l++;
            cnt--;
        }
        r++;
        res = max(cnt, res);
    }
    res = max(cnt, res);

    cout << res << "\n";

    

    

    return 0;
}



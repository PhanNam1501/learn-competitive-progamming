#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int k; 
    int r;
    
    cin >> n >> k >> r;
    vector<int> a(n, 0);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        a[x-1] = 1;
    }

    int cnt = 0;
    int li = 0;
    int ri = 0;
    int maxi = -1;
    int res = 0;
    // if (a[ri] == 1) cnt=1;
    // else maxi=0;
    

    for (int i = 0; i < n; i++) {
        if (i - li < r-1) {
            if (a[i] == 1) cnt++;
            else maxi = i;
        } else {
            if (a[i] == 1) cnt++;
            else maxi = i;

            if (cnt < 2) {
                while(cnt < 2) {
                    if (a[maxi] == 0) {
                        a[maxi] = 1;
                        res++;
                        cnt++;
                    } 
                    maxi--;
                    
                }
                if (a[li]==1) cnt--;
                li++;
            } else {
                while(cnt >= 2) {
                    if (a[li]==1) cnt--;
                    li++;
                }

            }
        }
    }

    cout << res << "\n";
    return 0;
}



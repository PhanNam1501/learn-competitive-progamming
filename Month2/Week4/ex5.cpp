
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        int q;
        cin >> n >> q;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            a[i] = x;
        }

        vector<long long> pre(n);
        pre[0] = a[0];
        for (int i = 1; i < n; i++) {
            pre[i] = a[i] ^ pre[i-1];
        }

        map<long long, vector<int>> myMap;
        for (int i = 0; i < n; i++) {
            myMap[pre[i]].push_back(i);
        }        

        while(q--) {
            int l;
            int r;
            cin >> l >> r;
            long long s = 0;
            if (l < 2) {
                s = pre[r-1];
            } else {
                s =  pre[r-1] ^ pre[l-2];
            }
            if (s == 0) cout << "YES" << "\n";
            else {
                int li = -1;
                int ri = -1;
                vector<int> &c1 = myMap[pre[r-1]];
                int l1 = 0;
                int h1 = c1.size() - 1;
                while(l1 <= h1) {
                    int m1 = (l1 + h1)/2;

                    if (c1[m1] >= (l-1)) {
                        li = c1[m1];
                        h1 = m1 - 1;
                    } else {
                        l1 = m1 + 1;
                    }
                }

                int u = l < 2 ? 0 : pre[l-2];
                vector<int> &c2 = myMap[u];
                int l2 = 0;
                int h2 =c2.size()-1;
                while(l2 <= h2) {
                    int m2 = (l2 + h2)/2;

                    if (c2[m2] <= r - 1) {
                        ri = c2[m2];
                        l2 = m2 + 1;
                    } else {
                        h2 = m2 - 1;
                    }
                }

                // for (int i = 0; i < c2.size(); i++) {
                //     cout << c2[i] << "\n";
                // }

                // cout << li << " " << ri << "\n";


                if (li < ri && li != -1 && ri != -1 && ri < (r-1)) {
                    cout << "YES" << "\n";
                } else {
                    cout << "NO" <<"\n";
                }


            }

            

            
            
        }

        cout << "\n";
    }

    return 0;
}

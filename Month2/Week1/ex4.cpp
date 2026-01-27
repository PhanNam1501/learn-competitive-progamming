#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin>>n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        int ans = -1; 
        for (int bit = 30; bit >= 0; bit--) {
            int cnt = 0;
            int last = -1;
            for (int i = 0; i < n; i++) {
                int ai = (a[i] >> bit) & 1;
                int bi = (b[i] >> bit) & 1;
                cnt+=(ai+bi);
                if (ai != bi) {
                    last=i;
                }
            }
            if(cnt%2==0) continue;
            if (last % 2 == 0) {
                ans=0;
            } else {
                ans=1;
            }

            break;
        }  
        if (ans == 0) {
            cout << "Ajisai";
        }
        else if (ans == 1) {
            cout << "Mai";
        }
        else {
            cout << "Tie"; 
        }
        cout << std::endl;
    }

    
    return 0;
}

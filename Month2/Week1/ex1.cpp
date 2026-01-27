#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;                 // số test case

    while (t--) {
        int n;
        long long k;
        cin >> n >> k;        

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];      
        }
        int ans = 0;

        for (int i = 30; i >= 0; i--) {
            long long need = 0;
            for (int j = 0; j < n; j++) {
                if (((a[j] >> i) & 1) == 0) {
                    need++;
                }
            }

            if (need <= k) {
                k -= need;
                ans |= (1LL << i);
            }
        }

        cout << ans << "\n";
        
    }

    

    return 0;
}



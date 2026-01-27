#include <bits/stdc++.h>
using namespace std;

void solve(int t) {
    long long N, K;
    cin >> N >> K;

    map<long long, long long> myMap;
    myMap[N] = 1;
    long long mx = 0, mn = 0;
    int check = 0;

    

    while (K != 0) {
        auto it = prev(myMap.end());
        long long high = it->first;
        long long cnt = it->second;
        
        long long left = (high - 1) / 2;
        long long right =  high / 2;

        if (K <= cnt) {
            mx = max(left, right);
            mn = min(left,right);
            cout << "Case #" << t << ": " << mx << " " << mn << "\n";
            break;
        }
        K -= cnt;
        myMap.erase(it);
        myMap[left] += cnt;
        myMap[right] += cnt;
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        solve(i+1);
    }

    

    



    return 0;
}
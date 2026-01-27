#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<bitset<3000>> match(N);

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = i + 1; j < N; j++) {
            if (s[j] == '1') {
                match[i][j] = 1;   
            }
        }
    }

    long long ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (match[i][j]) { 
                ans += (match[i] & match[j]).count();
            }
        }
    }

    cout << ans << "\n";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    vector<bitset<1000>> win(n), lose(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == 1) {
                win[i].set(j);
                lose[j].set(i);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == 1) {
                bitset<1000> s = win[j] & lose[i];
                if (s.any()) {
                    int k = s._Find_first(); 
                    cout << i + 1 << " " << j + 1 << " " << k + 1; 
                    return 0;
                }
            }
        }
    }

    cout << "-1 -1 -1";


    return 0;
}

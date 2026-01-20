#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    int maxA = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxA = max(maxA, a[i]);
    }

    vector<int> isPrime(maxA + 1, 0);
    if (maxA >= 0) isPrime[0] = 1;

    for (int i = 1; i <= maxA; i++) {
        for (int j = i; j <= maxA; j += i) {
            isPrime[j]++;
        }
        
    }

    for (int i = 0; i < n; i++) {
        cout << isPrime[a[i]] << "\n";
    }

    return 0;
}

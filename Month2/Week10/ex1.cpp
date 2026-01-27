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

    vector<bool> isPrime(maxA + 1, true);
    if (maxA >= 0) isPrime[0] = false;
    if (maxA >= 1) isPrime[1] = false;

    for (int i = 2; i * i <= maxA; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= maxA; j += i)
                isPrime[j] = false;
        }
    }

    for (int x : a) {
        cout << (isPrime[x] ? "YES\n" : "NO\n");
    }
}

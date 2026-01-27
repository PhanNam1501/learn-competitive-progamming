#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long l = 1;
    long long r = 1e9;
    long long m = 0;
    long long x = 0;

    while(l <= r) {
        m = (l+r)/2;

        cout << "? " << m << "\n";
        cout.flush();

        string ans;
        cin >> ans;

        if (ans == "YES") {
            l = m + 1;
        } else {
            x = m;
            r = m - 1;
        }
    }

    cout << "! " << x << "\n";
    cout.flush();

    return 0;
}

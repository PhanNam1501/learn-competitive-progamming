#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;              

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];      
    }

    set<long long> mySet;
    vector<long long> cur, next;
    for (int i = 0; i < n; i++) {
        next.clear();
        next.push_back(a[i]);
        for (long long x: cur) {
            next.push_back(x | a[i]);
        }
        next.erase(unique(next.begin(), next.end()), next.end());
        cur = next;
        for (long long x: cur) {
            mySet.insert(x);
        }
    }

    cout << mySet.size();

    return 0;
}

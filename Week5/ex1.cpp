#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    set<long long> mySet; 

    long long res = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        mySet.insert(a[i]);
        if (i != 0) {
            auto it = mySet.upper_bound(a[i]); 
            if (it != mySet.end()) {
                res = min(res, *it - a[i]);
            }
        }
    }

    cout << res << endl;

    return 0;
}

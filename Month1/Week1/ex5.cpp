#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool check(long long n) {
    return (n & (n - 1)) == 0;
}


int main() {
    int n;
    cin >> n;
    int count = 0;


    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; i++) {
        bool x = check(a[i]);
        if (x) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }

    return 0;
}
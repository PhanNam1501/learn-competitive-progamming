#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int count = 0;


    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            count += 1;
        }
    }
    if (n == 1 && a[0] == 1) {
        cout << "YES\n";
    } else if (n == 1 && a[0] == 0) {
        cout << "NO\n";       
    } else if (count == 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
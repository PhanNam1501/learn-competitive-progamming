#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    vector<int> a(t);
    for (int i = 0; i < t; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < t; i++) {
        cout << a[i] - 1 << endl;
    }

    return 0;
}

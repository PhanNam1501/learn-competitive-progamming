#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    set <long long> mySet;
    while (true) {
        int type;
        cin >> type;
        if (!cin || type == 0) break;


        if (type == 1 ) {
            long long x;
            cin >> x;
            mySet.insert(x);
        } else if (type == 2) {
            long long x; cin >> x;
            mySet.erase(x);
        } else if (type == 3) {
            if (!mySet.empty()) {
                auto it = mySet.begin();
                cout << *it << "\n";
            } else {
                cout << "empty" << "\n";
            }
        } else if (type == 4) {
            if (mySet.empty()) cout << "empty\n";
            else cout << *prev(mySet.end()) << '\n';
        } else if (type == 5) {
            long long x;
            cin >> x;
            if (mySet.empty()) cout << "empty" << "\n";
            else {
                auto it = mySet.upper_bound(x);
                if (it != mySet.end()) {
                    cout << *it << "\n";
                } else {
                    cout << "no" << "\n";
                }
            }
        } else if (type == 6) {
            long long x;
            cin >> x;
            if (mySet.empty()) cout << "empty" << "\n";
            else {
                auto it = mySet.lower_bound(x);
                if (it != mySet.end()) {
                    cout << *it << "\n";
                } else {
                    cout << "no" << "\n";
                }
            }  
        } else if (type == 7) {
            long long x;
            cin >> x;
            if (mySet.empty()) {
                cout << "empty\n";
            }

            auto it = mySet.lower_bound(x);
            if (it == mySet.begin()) cout << "no\n";
            else {
                it--;
                cout << *it << "\n";
            }
        } else if (type == 8) {
            long long x;
            cin >> x;
            if (mySet.empty()) {
                cout << "empty\n";
            }
            auto it = mySet.upper_bound(x);
            if (it == mySet.begin()) cout << "no\n";
            else {
                it--;
                cout << *it << "\n";
            }
        }
    }

    return 0;
}

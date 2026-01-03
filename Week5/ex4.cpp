#include <bits/stdc++.h>
using namespace std;

multiset<long long> r;
multiset<long long> l;




void rebalance() {
    if (l.size() > (r.size()+1)) {
        r.insert(*(l.rbegin()));
        l.erase(prev(l.end()));
    } else if (r.size() > l.size()) {
        auto it = r.begin();
        r.erase(it);
        l.insert(*it);
    }
}
void add(long long x) {
    if (l.size() == 0) {
        l.insert(x);
        return;
    }
    if (x > *(l.rbegin())) {
        r.insert(x);
    } else {
        l.insert(x);
    }

    rebalance();
}

void remove(long long x) {
    if (x <= *(l.rbegin())) {
        multiset<long long>::iterator it = l.find(x);
        if (it != l.end()) l.erase(it);
    } else {
        multiset<long long>::iterator it = r.find(x);
        if (it != r.end()) r.erase(it);
    }

    rebalance();
}

void median() {
    if (l.size() == 0) {
        cout << 0 << endl;
        return;
    } else {
        if (l.size() == r.size()) {
            
            // cout << *it << " " << *it1 << "\n";
            double median = (*(l.rbegin()) + *(r.begin())) / 2.0;
            if (long(median) == median) cout << long(median) << endl;
            else cout << fixed << setprecision(1) << median << endl;
        } else {
            cout << *(l.rbegin()) << endl;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    if (!(cin >> Q)) return 0;

    while (Q--) {
        string type;
        cin >> type;
        if (type == "IN") {
            long long x;
            cin >> x;
            add(x);
        } else if (type == "OUT") {
            long long x;
            cin >> x;
            remove(x);
        } else if (type == "MEDIAN") {
            median();
        }
    }

    return 0;
}
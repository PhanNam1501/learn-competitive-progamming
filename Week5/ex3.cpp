#include <bits/stdc++.h>
using namespace std;

// struct Node {
//     int id;
//     long long left, right;
// };

// struct Compare {
//     bool operator()(const Node& x, const Node& y) const {
//         return x.right < y.right;
//     }
// };



int main() {
    int n;
    cin >> n ;  

    vector<pair<long long, long long>> lines(n);  

    for (int i = 0; i < n; i++) {
        cin >> lines[i].first >> lines[i].second;  
    }

    // sort(lines.begin(), lines.end());

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b) {
        if (lines[a].first != lines[b].first)
            return lines[a].first < lines[b].first;
        return lines[a].second > lines[b].second;
    });

    vector<long long> f(n);
    vector<long long> s(n);
    // s.push_back(0);

    // multiset<long long> mySet;
    multiset<long long> mySet;
    for (int t = 0; t < n; t++) {
        int i = idx[t];
        if (mySet.size() != 0) {
            auto it = mySet.lower_bound(lines[i].second);
            if (it != mySet.end()) {
                s[i] = 1;
            } else {
                s[i] = 0;
            }
            mySet.insert(lines[i].second);
        } else {
            mySet.insert(lines[i].second);
            s[i] = 0;
        }
    }
    vector<int> idx1(n);
    iota(idx1.begin(), idx1.end(), 0);
    sort(idx1.begin(), idx1.end(), [&](int a, int b) {
        if (lines[a].first != lines[b].first)
            return lines[a].first > lines[b].first;
        return lines[a].second < lines[b].second;
    });

    multiset<long long> mySet1;
    for (int t = 0; t < n; t++) {
        int i = idx1[t];
        // cout << i << "\n";
        if (mySet1.size() != 0) {
            // auto it = mySet1.upper_bound(lines[i].second);
            if (lines[i].second >= *(mySet1.begin())) {
                f[i] = 1;
            } else {
                f[i] = 0;
            }
            mySet1.insert(lines[i].second);
        } else {
            mySet1.insert(lines[i].second);
            f[i] = 0;
        }
    }


    for (int i = 0; i < n; i++) {
        cout << f[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << s[i] << " ";
    }



    
    return 0;
}

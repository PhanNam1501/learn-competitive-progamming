#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<bool> isPrime(n + 1, true);
    if (n >= 0) isPrime[0] = false;
    if (n >= 1) isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }


    vector<vector<int>> prime(n+1);
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i; j <= n; j+= i) {
                prime[j].push_back(i);
            }
        }
        // for (int j = i; j <= n; j+= i) {
        //     prime[j].push_back(i);
        // }
    }

    // for (int i = 0; i < n+1; i++) {
    //     for (int j = 0; j < prime[i].size(); j++) {
    //         cout << prime[i][j] << "\n";
    //     }
    // }


    unordered_map<int, set<int>> myMap;
    for (int i = 0; i < m; i++) {
        char op;
        int x;
        cin >> op >> x;  
        if (op == '+') {
            if (x == 1) {
                auto it = myMap[1].find(1);
                if (it != myMap[1].end()) {
                    cout << "Already on" << "\n";
                } else {
                    myMap[1].insert(1);
                    cout << "Success" << "\n";
                }
                
            } else {
                bool check = true;
                for (int i = 0; i < prime[x].size(); i++) {
                    if (!myMap[prime[x][i]].empty()) {
                        auto it = myMap[prime[x][i]].find(x);
                        if (it != myMap[prime[x][i]].end()) {
                            cout << "Already on" << "\n";
                        } else {
                            cout << "Conflict with " << *myMap[prime[x][i]].begin() << "\n";
                        }
                        check = false;
                        break;
                    }
                }
                if (check) {
                    for (int i = 0; i < prime[x].size(); i++) {
                        myMap[prime[x][i]].insert(x);
                    }
                    cout << "Success" << "\n";
                }
            }
        } else if (op == '-') {
            if (x == 1) {
                auto it = myMap[1].find(1);
                if (it != myMap[1].end()) {
                    myMap[1].erase(it);
                    cout << "Success" << "\n";
                } else {
                    cout << "Already off" << "\n";
                }
            } else {
                bool check = false;
                for (int i = 0; i < prime[x].size(); i++) {
                    if (!myMap[prime[x][i]].empty()) {
                        auto it = myMap[prime[x][i]].find(x);
                        if (it != myMap[prime[x][i]].end()) {
                            myMap[prime[x][i]].erase(it);
                            check = true;
                        } 
                    }
                }

                if (check) {
                    cout << "Success" << "\n";
                } else {
                    cout << "Already off" << "\n";
                }
            }
        }
    }

    return 0;
}

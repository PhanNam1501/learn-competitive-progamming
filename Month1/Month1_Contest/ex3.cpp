#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    priority_queue <long long> pq;     
    string s;
    while (cin >> s) {
        if (s[0] == '+') {
            long long v = stoll(s.substr(1));
            if (pq.size() < 15000) {
                pq.push(v);
            }
        } else if (s == "-") {
            if (!pq.empty()) {
                long long t = pq.top();
                while(!pq.empty() && pq.top() == t) {
                    pq.pop();
                }
            }
        }
    }
    int cnt = 0;
    vector<long long> res;
    long long last = 0;
    while(!pq.empty()) {
        last = pq.top();
        while(!pq.empty() && pq.top() == last) {
            pq.pop();
        }
        res.push_back(last);
        cnt++;
    }
    cout << cnt << "\n";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << "\n";
    }
    return 0;
}

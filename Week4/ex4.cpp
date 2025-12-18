#include <bits/stdc++.h>
using namespace std;

struct Node {
    int idx;
    long long r;
    bool operator<(const Node& other) const {
        return r > other.r; 
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<long long> l(n), r(n);
    for (int i = 0; i < n; i++) 
        cin >> l[i] >> r[i];

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b) {
        return l[a] < l[b];
    });

    priority_queue<Node> pq;
    long long maxLen = 0;
    int bestT = -1; 

    for (int t = 0; t < n; t++) {
        int i = idx[t];
        pq.push({i, r[i]});
        
        while ((int)pq.size() > k) 
            pq.pop();

        if ((int)pq.size() == k) {
            long long len = pq.top().r - l[i] + 1;
            if (len > maxLen) {
                maxLen = len;
                bestT = t; 
            }
        }
    }

    cout << maxLen << "\n";

    if (maxLen == 0) {
        for (int i = 1; i <= k; i++) 
            cout << i << " ";
    } else {
        vector<pair<long long, int>> candidates;
        for (int t = 0; t <= bestT; t++) {
            int i = idx[t];
            candidates.push_back({r[i], i + 1});
        }
        
        sort(candidates.begin(), candidates.end(), greater<pair<long long, int>>());
        
        vector<int> ans;
        for (int j = 0; j < k; j++) {
            ans.push_back(candidates[j].second);
        }
        sort(ans.begin(), ans.end());
        
        for (int x : ans) 
            cout << x << " ";
    }

    return 0;
}
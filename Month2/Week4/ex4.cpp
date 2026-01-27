#include <bits/stdc++.h>
using namespace std;

bool check(vector<pair<int, int>> &a) {
    sort(a.begin(), a.end());
    priority_queue <int,vector <int>,greater <int>>pq;
    int p = 0;
    for (int column = 1; column <= a.size(); column++) { 
        while(!pq.empty() && (pq.top() < column)) {
            pq.pop();
        }

        while(p < a.size() && a[p].first <= column) {
            pq.push(a[p].second);
            p++;
        }

        if (pq.empty()) {
            return false;
        } else {
            pq.pop();
        }
    }

    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> a(n+1);
    for (int i = 1; i <= n; i++) {
        int x;
        int y;
        cin >> x >> y;
        a[i] = {x, y};
    }

    int l = 0;
    int h = 100000007;
    int ans = -1;
    while (l <= h) {
        int m = (h+l)/2;
        vector<pair<int,int>> d;
        for (int i = 1; i <= n; i++) {
            d.push_back(make_pair(max(1, a[i].first - m/a[i].second), min(n, a[i].first + m/a[i].second)));
        }

        if (check(d)) {
            ans = m;
            h = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << ans << "\n";
    
    return 0;
}

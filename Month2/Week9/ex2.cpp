#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;

    vector<pair<long long, int>> trees(n);
    for (int i = 0; i < n; i++) {
        cin >> trees[i].first >> trees[i].second;
    }

    sort(trees.begin(), trees.end());

    int l = 0;
    int cntA = 0, cntB = 0;
    long long ans = LLONG_MAX;

    for (int r = 0; r < n; r++) {
        if (trees[r].second == 1) cntA++;
        else cntB++;

        while (cntA >= a && cntB >= b) {
            ans = min(ans, trees[r].first - trees[l].first);

            if (trees[l].second == 1) cntA--;
            else cntB--;
            l++;
        }
    }

    cout << (ans == LLONG_MAX ? -1 : ans) << "\n";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int id(char c) {
    if (c == 'A') return 0;
    if (c == 'C') return 1;
    if (c == 'G') return 2;
    return 3; // T
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    vector<array<int,4>> next_pos(n + 1);
    for (int c = 0; c < 4; c++) next_pos[n][c] = -1;

    for (int i = n - 1; i >= 0; i--) {
        next_pos[i] = next_pos[i + 1];
        next_pos[i][id(s[i])] = i + 1;
    }

    queue<int> q;
    vector<int> parent(n + 1, -1);
    vector<char> parent_char(n + 1);

    q.push(0);
    parent[0] = -2; 

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (char c : {'A', 'C', 'G', 'T'}) {
            int v = next_pos[u][id(c)];

            if (v == -1) {
                string ans;
                ans.push_back(c);
                while (parent[u] != -2) {
                    ans.push_back(parent_char[u]);
                    u = parent[u];
                }
                reverse(ans.begin(), ans.end());
                cout << ans;
                return 0;
            }

            if (parent[v] == -1) {
                parent[v] = u;
                parent_char[v] = c;
                q.push(v);
            }
        }
    }
}

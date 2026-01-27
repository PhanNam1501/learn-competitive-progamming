#include <bits/stdc++.h>
using namespace std;


int get_id(char c) {
    if (c == 'A') return 0;
    if (c == 'C') return 1;
    if (c == 'G') return 2;
    return 3;
}

int main() {
    string s:
    cin >> s;
    int n = s.size();

    vector<array<int, 4>> next_pos(n + 1);
    for (int i = 0; i < 4; i++) next_pos[n][i] = -1;
    
    for (int i = n - 1; i >= 0; i--) {
        next_post[i] = next_post[i + 1];
        next_post[i][get_id(s[i])] = i + 1;
    }

    queue<int> q;
    vector<int> parent(n+1, -1);
    vector<char> parent_char(n+1)

    q.push(0);
    parent[0] = -2;

    while (!q.empty()) {
        u = q.front();
        q.pop();

        for (char c: {'A', 'C', 'G', 'T'}) {
            int v = next_post[u][get_id(c)];

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
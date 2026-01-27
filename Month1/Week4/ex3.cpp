#include <bits/stdc++.h>
using namespace std;
struct Node {
    long long sum;
    int i, j;

};

struct Cmp {
    bool operator()(const Node& a, const Node& b) const {
        return a.sum > b.sum;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N, K;
    cin >> M >> N >> K;

    vector<long long> A(M), B(N);
    for (int i = 0; i < M; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());


    pq.push({A[0] + B[0], 0, 0});
    visited.insert({0, 0});

    while (!pq.empty() && cnt < K) {
        auto cur = pq.top(); pq.pop();
        cnt++;

        cout << cur.sum << "\n";

        int i = cur.i;
        int j = cur.j;

        if (i + 1 < M && !visited.count({i + 1, j})) {
            pq.push({A[i + 1] + B[j], i + 1, j});
            visited.insert({i + 1, j});
        }

        if (j + 1 < N && !visited.count({i, j + 1})) {
            pq.push({A[i] + B[j + 1], i, j + 1});
            visited.insert({i, j + 1});
        }
    }

    
  


    return 0;
}

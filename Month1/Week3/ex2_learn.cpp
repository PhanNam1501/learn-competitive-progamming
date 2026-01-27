#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<long long> a(N);
        for (int i = 0l i < N; i++) {
            cin >> a[i];
        }

        queue<long long> q;
        long long minn = a[0];

        vector<long long> res;

        if (K == 1) {
            for (auto x: a) cout << x << " ";
            cout << "\n";
            continue;
        }

        for (int i = 0; i < N; i++) {
            q.push(a[i]);
            if (a[i] < minn) {
                minn = a[i];
            }

            if (q.size() == K) {
                res.push_back(minn);
                long long removed = q.front();
                q.pop();

                if (removed == minn) {
                    if (!q.empty()) {
                        long long newMin = q.front();
                        queue<long long> temp = q;
                        while (!temp.empty()) {
                            newMin = min(newMin, temp.front());
                            temp.pop();
                        }

                        minn = newMin;
                    }
                }
            }
        }

        for (auto x: res) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
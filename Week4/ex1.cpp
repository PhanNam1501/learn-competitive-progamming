#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;   

        vector<long long> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }

        priority_queue <long long, vector <long long>, greater <long long>> pqMin;
        for (int i = 0; i < N; i++) {
            pqMin.push(a[i]);
        }

        long long totalCost = 0;

        while (pqMin.size() > 1) {
            long long x = pqMin.top(); pqMin.pop();
            long long y = pqMin.top(); pqMin.pop();

            long long z = x + y;
            totalCost += z;
            pqMin.push(z);
        }

        cout << totalCost << "\n";
    }

    

    return 0;
}

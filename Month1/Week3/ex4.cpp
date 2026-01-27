#include <bits/stdc++.h>
using namespace std;

// int getMin(queue<int> q) {
//     if (q.size() < 2) return 0; 

//     queue<int> temp = q;
//     int res = 0;

//     int t = temp.front();
//     temp.pop();

//     while (!temp.empty()) {
//         int t1 = temp.front();
//         temp.pop();
//         res = max(res, abs(t - t1));
//         t = t1;
//     }
//     return res;
// }



int main() {
    int n, m;
    cin >> n >> m; 

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        v.push_back({a[i], b[i]});
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        a[i] = v[i].first;
        b[i] = v[i].second;
    }

    queue<int> q;
    queue<int> maxxq;
    int maxx = 0;
    int l = 0;
    int summ = 0;
    int minn = INT_MAX;
    for (int i = 0; i < n; i++) {
            summ += b[i];
            if (i > 0) {
                int gap = a[i] - a[i-1];
                maxx = max(gap, maxx);
                maxxq.push(gap);
            }

            while (summ >= m) {
                minn = min(minn, maxx);

                summ -= b[l];
                if (l + 1 <= i) {
                    if (!maxxq.empty()) {
                        int temp = maxxq.front();
                        maxxq.pop();
                        if (temp == maxx) {
                            queue<int> tmp = maxxq;
                            maxx = 0;
                            while (!tmp.empty()) {
                                maxx = max(maxx, tmp.front());
                                tmp.pop();
                            }
                        }
                    }
                }
                l++;
            }
            
        
    }

    cout << minn;
}

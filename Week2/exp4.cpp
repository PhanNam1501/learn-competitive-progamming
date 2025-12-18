#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // nearest smaller to left
    vector<int> L(n);
    stack<int> stl;

    for (int i = 0; i < n; i++) {
        while (!stl.empty() && a[stl.top()] >= a[i])
            stl.pop();
        if (stl.empty()) L[i] = -1;
        else L[i] = stl.top();
        stl.push(i);
    }

    // nearest smaller to right
    vector<int> R(n);
    stack<int> str;

    for (int i = n - 1; i >= 0; i--) {
        while (!str.empty() && a[str.top()] >= a[i])
            str.pop();
        if (str.empty()) R[i] = n;
        else R[i] = str.top();
        str.push(i);
    }

    long long ans = 0;

    cout << L[0] << "\n";

    for (int i = 0; i < n; i++) {
        long long height = a[i];
        long long width = R[i] - L[i] - 1;
        ans = max(ans, height * width);
    }

    cout << ans;
    return 0;
}

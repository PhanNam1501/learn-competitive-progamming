#include <bits/stdc++.h>
using namespace std;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, target;
    cin >> N >> target; 
    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    map <long long, int> mymap; 
    bool check = false;

    for (int i = 0; i < N; i++) {
        if (a[i] <= target) {
            int t = target - a[i];
            if ((mymap[t] != 0) && (mymap[t] != (i + 1))) {
                check = true;
                cout << mymap[t] <<" "<< i+1 << "\n";
                break;
            } 
            mymap[a[i]] = i+1;
        }
    }
    if (check == false) {
        cout << "IMPOSSIBLE" << "\n";

    }

    



    return 0;
}
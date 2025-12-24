#include <bits/stdc++.h>
using namespace std;


int count(vector<int> &arr) {
    int l = 0;
    int h = arr.size() - 1;

    if (arr.size() == 1) return arr[0];
    // if (arr[arr.size() - 1] == 1) return arr.size() - 1; 

    while (l <= h) {
        int m = l + (h-l)/2;
        if (arr[m] == 1 && (arr[m+1] == 0 || m == arr.size() - 1)) {
            return m;
        } 

        if (arr[m] == 1 && arr[m+1] == 1) {
            l = m+1;
        } else {
            h = m-1;
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {0, 0, 0, 0, 0, 0, 0};
    cout << count(arr) + 1;
}

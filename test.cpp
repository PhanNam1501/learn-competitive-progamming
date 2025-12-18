#include <bits/stdc++.h>
using namespace std;

int maxOnes(vector<int>& arr, int k) {
        int count = 0;
        vector<int> blank;
        int idx = 0;

        while (idx < arr.size()) {
            int x = 0;
            while (arr[idx] == 1 && idx < arr.size()) {
                x++;
                idx++;
            }
            count++;
            if (x!=0) blank.push_back(x);

            int c = 0;
            while (arr[idx] != 1 && idx < arr.size()) {
                c++;
                idx++;
            }
            count++;
            if (c!=0) blank.push_back(c);
        }
        queue<int> q;
        int maxx = 0;
        int check = 0;
        int res = 0;
        int j = 0;
        if (arr[j] == 1) {
            j = 1;
        }

        for (int i = j; i < blank.size(); i+=2) {
            while(!q.empty() && check >= k) {
                int temp = q.front();
                maxx -= (blank[temp-1] + blank[temp]);
                check -= blank[temp];
            }
            
            check += blank[i];
            int t = check > k ? check - k : 0;
            if (i == blank.size() - 2 && t == 0) {
                maxx += blank[i-1] + blank[i] + blank[i+1];
            } else {
                if (j == 0) {
                    maxx += blank[i];
                } else {
                    maxx += blank[i-1] + blank[i];
                }
            }
            q.push(i);
            
            res = max(res, maxx - t);
        }
        return res;
    }

int main() {
    vector<int> arr = {0,1,0,0,1,0};
    int res = maxOnes(arr, 1);
    cout << res;
    
}



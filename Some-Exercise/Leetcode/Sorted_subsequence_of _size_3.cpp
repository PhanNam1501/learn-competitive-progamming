// Function to find three numbers in the given array
// such that arr[smaller[i]] < arr[i] < arr[greater[i]]

//Way of PhanNam
class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        // Code here
        int l = -1;
        int m = -1;
        int ltemp = -1;
        int mtemp = -1;
        for (int i = 0; i < arr.size(); i++) {
            if (i == 0) {
                l = arr[i];
                continue;
            }
            
            if (m == -1 && arr[i] > l) {
                m = arr[i];
                continue;
            } else if (m == -1 && arr[i] < l) {
                l = arr[i];
                continue;
            }
            
            if (m != -1 && arr[i] > m) {
                return {l, m, arr[i]};
            }
            
            if (mtemp != -1 && arr[i] > mtemp) {
                return {l, mtemp, arr[i]};
            }
            
            if (arr[i] > ltemp && ltemp != -1) {
                if (arr[i] < m) {
                    m = arr[i];
                    l = ltemp;
                    continue;
                }
            }
            
            if (arr[i] <= m) {
                if (arr[i] > l) {
                    mtemp = arr[i];
                    continue;
                }
                ltemp = arr[i];
            }
        }
        
        return {};
    }
};


//Other way
#include <bits/stdc++.h>
using namespace std;

// A function to find a sorted sub-sequence of size 3
vector<int> find3Numbers(vector<int> &arr)
{
    int n = arr.size();

    // Fill smaller[] such that smaller[i] stores the
    // index of a smaller element on the left side
    vector<int> smaller(n, -1);
    int min = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] <= arr[min])
            min = i;
        else
            smaller[i] = min;
    }

    // Fill greater[] such that greater[i] stores the
    // index of a greater element on the right side
    vector<int> greater(n, -1);
    int max = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] >= arr[max])
            max = i;
        else
            greater[i] = max;
    }

    // Find the triplet
    for (int i = 0; i < n; i++)
    {
        if (smaller[i] != -1 && greater[i] != -1)
            return {arr[smaller[i]], arr[i], arr[greater[i]]};
    }

    // If no such triplet is found, return an empty vector
    return {};
}

// Driver code
int main()
{
    vector<int> arr = {12, 11, 10, 5, 6, 2, 30};
    vector<int> res = find3Numbers(arr);
    for (int x : result)
        cout << x << " ";
    return 0;
}


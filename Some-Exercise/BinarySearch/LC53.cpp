#include<bits/stdc++.h> 
using namespace std;

int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size() - 1;
        if (target < nums[0]) return 0;
        int c = -1;
        int m = -1;
        while (l <= h) {
            m = l + (h-l)/2;

            if (nums[m] == target) {
                return m;
            }

            if (nums[m] < target) {
                if (l < h) {
                    c = h;
                }
                l = m + 1;
            } else {
                if (l < h) {
                    c = l;
                }
                h = m - 1;
            }
        }

        return c + 1;
    }

    int main() {
        vector<int> res{1, 3, 5, 6};
        int target = 7;
        cout << searchInsert(res, target);
    }
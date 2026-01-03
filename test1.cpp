#include <bits/stdc++.h>
using namespace std;

int longestMonotonicSubarray(vector<int> &nums)
{
    int count = 0;
    int maxx = 0;
    int direct = -1;
    for (int i = 0; i < nums.size(); i++)
    {   
        cout << count << "\n";
        if (i == 0)
        {
            count++;
            maxx = max(maxx, count);
        }
        else
        {
            if (nums[i] > nums[i - 1])
            {
                if (direct != 0)
                {
                    count++;
                    direct = 1;
                }
                else
                {
                    count = 1;
                    direct = 0;
                }
                maxx = max(maxx, count);
            }
            else if (nums[i] < nums[i - 1])
            {
                cout << "hhh\n";
                if (direct != 1)
                {
                    count++;
                    direct = 0;
                }
                else
                {
                    count = 1;
                    direct = 1;
                }
                maxx = max(maxx, count);
            }
        }
    }

    maxx = max(maxx, count);

    return maxx;
}

int main()
{
    vector<int> nums1 = {3, 2, 1};
    int res = longestMonotonicSubarray(nums1);
    cout << res;
}
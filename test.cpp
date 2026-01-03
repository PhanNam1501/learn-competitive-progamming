#include <bits/stdc++.h>
using namespace std;

vector<int> getGreater(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && (nums[i] >= nums[st.top()]))
        {
            st.pop();
        }
        if (st.empty())
            res[i] = n;
        else
            res[i] = st.top();
        st.push(i);
    }
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << "\n";
    }
    return res;
}
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> myMap;
    vector<int> c = getGreater(nums2);
    for (int i = 0; i < nums2.size(); i++)
    {
        int next_id = c[i];
        if (next_id < nums2.size())
        {
            myMap[nums2[i]] = nums2[next_id];
        }
    }

    vector<int> res;

    for (int i = 0; i < nums1.size(); i++)
    {
        auto it = myMap.find(nums1[i]);
        if (it != myMap.end())
        {
            res.push_back(it->second);
        }
        else
        {
            res.push_back(-1);
        }
    }

    return res;
}

int main()
{
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    vector<int> res = nextGreaterElement(nums1, nums2);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << "\n";
    }
}

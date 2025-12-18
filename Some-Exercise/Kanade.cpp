class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int res = arr[0];
        int maxending = arr[0];
        
        for (int i = 1; i < arr.size(); i++) {
            maxending = max(arr[i], maxending + arr[i]);
            
            res = max(res, maxending);
        }
        
        return res;
        
    }
};
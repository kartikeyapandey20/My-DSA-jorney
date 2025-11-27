class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long maxSum = LLONG_MIN;
        
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        vector<long long> minPrefix(k, LLONG_MAX);
        
        minPrefix[0] = 0;
        
        for (int j = 1; j <= n; j++) {
            int remainder = j % k;
            
            if (minPrefix[remainder] != LLONG_MAX) {
                maxSum = max(maxSum, prefix[j] - minPrefix[remainder]);
            }
            
            minPrefix[remainder] = min(minPrefix[remainder], prefix[j]);
        }
        
        return maxSum;
    }
};
class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        
        multiset<int> window;
        int left = 0;
        long long sum = 1; 
        
        for (int i = 0; i < n; i++) {
            window.insert(nums[i]);
            
            // Shrink window while max - min > k
            while (left <= i && *window.rbegin() - *window.begin() > k) {
                sum = (sum - dp[left] + MOD) % MOD;
                
                // Remove nums[left] from window
                window.erase(window.find(nums[left]));
                left++;
            }
            
            // dp[i+1] = sum of dp[left] to dp[i]
            dp[i + 1] = sum;
            sum = (sum + dp[i + 1]) % MOD;
        }
        
        return dp[n];
    }
};
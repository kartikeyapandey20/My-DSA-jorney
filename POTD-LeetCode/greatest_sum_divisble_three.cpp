class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, INT_MIN);
        dp[0] = 0; 
        for (int num : nums) {
            vector<int> temp = dp;
            int r = num % 3;
            
            for (int i = 0; i < 3; i++) {
                if (temp[i] != INT_MIN) {
                    int newRemainder = (i + r) % 3;
                    dp[newRemainder] = max(dp[newRemainder], temp[i] + num);
                }
            }
        }
        
        return dp[0];
    }
};
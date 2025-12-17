class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        
        vector<vector<vector<long long>>> dp(n, 
            vector<vector<long long>>(k + 1, vector<long long>(3, -1e18)));
        
        dp[0][0][0] = 0; 
        dp[0][0][1] = -prices[0];
        dp[0][0][2] = prices[0];
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= k; j++) {
            
                dp[i][j][0] = dp[i-1][j][0];
                if (j > 0) {
                    dp[i][j][0] = max(dp[i][j][0], dp[i-1][j-1][1] + prices[i]);
                    dp[i][j][0] = max(dp[i][j][0], dp[i-1][j-1][2] - prices[i]);
                }
                
                dp[i][j][1] = dp[i-1][j][1];
                dp[i][j][1] = max(dp[i][j][1], dp[i-1][j][0] - prices[i]);
                
                dp[i][j][2] = dp[i-1][j][2];
                dp[i][j][2] = max(dp[i][j][2], dp[i-1][j][0] + prices[i]);
            }
        }
    
        long long maxProfit = 0;
        for (int j = 0; j <= k; j++) {
            maxProfit = max(maxProfit, dp[n-1][j][0]);
        }
        
        return maxProfit;
    }
};
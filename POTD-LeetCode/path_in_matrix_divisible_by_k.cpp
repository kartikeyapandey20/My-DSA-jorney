class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
       const int MOD = 1e9 + 7;
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));
        
        dp[0][0][grid[0][0] % k] = 1;
        
        for (int j = 1; j < n; j++) {
            for (int r = 0; r < k; r++) {
                if (dp[0][j-1][r] > 0) {
                    int newRemainder = (r + grid[0][j]) % k;
                    dp[0][j][newRemainder] = (dp[0][j][newRemainder] + dp[0][j-1][r]) % MOD;
                }
            }
        }
        
        for (int i = 1; i < m; i++) {
            for (int r = 0; r < k; r++) {
                if (dp[i-1][0][r] > 0) {
                    int newRemainder = (r + grid[i][0]) % k;
                    dp[i][0][newRemainder] = (dp[i][0][newRemainder] + dp[i-1][0][r]) % MOD;
                }
            }
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                for (int r = 0; r < k; r++) {
                    
                    if (dp[i-1][j][r] > 0) {
                        int newRemainder = (r + grid[i][j]) % k;
                        dp[i][j][newRemainder] = (dp[i][j][newRemainder] + dp[i-1][j][r]) % MOD;
                    }
                    
                    if (dp[i][j-1][r] > 0) {
                        int newRemainder = (r + grid[i][j]) % k;
                        dp[i][j][newRemainder] = (dp[i][j][newRemainder] + dp[i][j-1][r]) % MOD;
                    }
                }
            }
        }
        
        return dp[m-1][n-1][0]; 
    }
};
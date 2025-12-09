class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        const int MAXVAL = 200001;
        int n = nums.size();
        long long count = 0;
        
        vector<int> rightCount(MAXVAL, 0);
        vector<int> leftCount(MAXVAL, 0);
        
        for (int num : nums) {
            rightCount[num]++;
        }
        
        for (int j = 0; j < n; j++) {
            rightCount[nums[j]]--;
            
            if (j > 0 && j < n - 1) {
                long long target = (long long)nums[j] * 2;
                
                if (target < MAXVAL) {
                    long long left = leftCount[target];
                    long long right = rightCount[target];
                    
                    count = (count + (left * right) % MOD) % MOD;
                }
            }
            
            leftCount[nums[j]]++;
        }
        
        return count;
    }
};
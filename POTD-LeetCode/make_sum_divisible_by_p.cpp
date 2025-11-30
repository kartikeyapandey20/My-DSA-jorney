class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        
        long long totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        int target = totalSum % p;
        
        if (target == 0) return 0;
        
        unordered_map<int, int> prefixMod;
        prefixMod[0] = -1;
        
        int minLen = n;
        long long prefixSum = 0;
        
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            int currMod = prefixSum % p;
            
            int needed = (currMod - target + p) % p;
            
            if (prefixMod.find(needed) != prefixMod.end()) {
                minLen = min(minLen, i - prefixMod[needed]);
            }
            
            prefixMod[currMod] = i;
        }
        
        return minLen == n ? -1 : minLen;
    }
};
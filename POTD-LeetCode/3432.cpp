class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        if (totalSum % 2 == 1) {
            return 0;
        }
        
        return n - 1;
    }
};
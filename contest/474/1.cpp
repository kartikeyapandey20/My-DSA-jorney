class Solution {
public:

    bool isPresent(int n , vector<int> nums){
        for(int i = 0; i < nums.size(); i++){
            if(n == nums[i]){
                return true;
            }
        }

        return false;
    }
    vector<int> findMissingElements(vector<int>& nums) {
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> ans;

        for(int i = minVal + 1; i < maxVal; i++){
            if(!isPresent(i,nums)){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};
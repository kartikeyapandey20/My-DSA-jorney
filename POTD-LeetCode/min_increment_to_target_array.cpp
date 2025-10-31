class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int res = target[0];
        int n = target.size();

        for(int i = 1; i < n; i++){
            res += max(target[i] - target[i - 1], 0);
        }

        return res; 
    }
};
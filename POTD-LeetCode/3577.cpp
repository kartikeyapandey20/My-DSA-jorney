class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        const int MOD = 1e9 + 7;
        int n = complexity.size();
        
        for (int i = 1; i < n; i++) {
            bool canUnlock = false;
            for (int j = 0; j < i; j++) {
                if (complexity[j] < complexity[i]) {
                    canUnlock = true;
                    break;
                }
            }
            if (!canUnlock) return 0;
        }
        
        bool isMin = true;
        for (int i = 1; i < n; i++) {
            if (complexity[i] <= complexity[0]) {
                isMin = false;
                break;
            }
        }
        
        if (isMin) {
            long long result = 1;
            for (int i = 1; i < n; i++) {
                result = (result * i) % MOD;
            }
            return result;
        }
        
        return 0;
    }
};
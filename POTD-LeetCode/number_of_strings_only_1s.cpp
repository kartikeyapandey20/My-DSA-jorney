class Solution {
public:
    int numSub(string s) {
        const int MOD = 1e9 + 7;
        long long result = 0;
        int count = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                count++;
            } else {
                if (count > 0) {
                    long long contribution = (long long)count * (count + 1) / 2;
                    result = (result + contribution) % MOD;
                    count = 0;
                }
            }
        }
        
        if (count > 0) {
            long long contribution = (long long)count * (count + 1) / 2;
            result = (result + contribution) % MOD;
        }
        
        return result;
    }
};
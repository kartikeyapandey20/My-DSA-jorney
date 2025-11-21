class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        int result = 0;
        
        for (char c = 'a'; c <= 'z'; c++) {
            int first = -1, last = -1;
            
            for (int i = 0; i < n; i++) {
                if (s[i] == c) {
                    if (first == -1) {
                        first = i;
                    }
                    last = i;
                }
            }
            
            if (first != -1 && first < last) {
                unordered_set<char> unique_middle;
                
                for (int i = first + 1; i < last; i++) {
                    unique_middle.insert(s[i]);
                }
                
                result += unique_middle.size();
            }
        }
        
        return result;
    }
};
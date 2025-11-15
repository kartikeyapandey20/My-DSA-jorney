class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int result = 0;
        
        vector<int> zeroPos;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                zeroPos.push_back(i);
            }
        }
        
        int maxZeros = sqrt(n) + 1;
        
        for (int i = 0; i < n; i++) {
            for (int numZeros = 0; numZeros <= maxZeros; numZeros++) {
                int zeroIdx = lower_bound(zeroPos.begin(), zeroPos.end(), i) - zeroPos.begin();
                
                if (zeroIdx + numZeros > zeroPos.size()) {
                    if (numZeros == 0) {
                        result += n - i;
                    }
                    break;
                }
                
                int start, end;
                
                if (numZeros == 0) {
                    start = i;
                    if (zeroIdx < zeroPos.size()) {
                        end = zeroPos[zeroIdx] - 1;
                    } else {
                        end = n - 1;
                    }
                    
                    if (end >= start) {
                        result += end - start + 1;
                    }
                } else {
                    
                    int lastZeroPos = zeroPos[zeroIdx + numZeros - 1];
                    
                    start = lastZeroPos;
                    
                    if (zeroIdx + numZeros < zeroPos.size()) {
                        end = zeroPos[zeroIdx + numZeros] - 1;
                    } else {
                        end = n - 1;
                    }
                    
                    int minEnd = i + numZeros + numZeros * numZeros - 1;
                    
                    if (minEnd <= end && start <= end) {
                        int validStart = max(start, minEnd);
                        if (validStart <= end) {
                            result += end - validStart + 1;
                        }
                    }
                }
            }
        }
        
        return result;
    }
};
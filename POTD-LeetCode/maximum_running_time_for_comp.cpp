class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long left = 1;
        long long right = 0;
        
        for (int battery : batteries) {
            right += battery;
        }
        right /= n; 

        long long answer = 0;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            
            if (canRun(n, batteries, mid)) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return answer;
    }
    
    bool canRun(int n, vector<int>& batteries, long long targetTime) {
        long long pooledPower = 0;
        int dedicatedCount = 0;
        
        for (int battery : batteries) {
            if (battery >= targetTime) {
                dedicatedCount++;
            } else {
                pooledPower += battery;
            }
        }
        
        int additionalComputers = pooledPower / targetTime;
        
        return dedicatedCount + additionalComputers >= n;
    }
};
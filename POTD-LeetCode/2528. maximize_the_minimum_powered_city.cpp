class Solution {
public:
      bool canAchieve(long long target, const vector<long long>& power, int r, long long k, int n) {
        vector<long long> diff(n+1, 0);
        long long used = 0;
        long long addRunning = 0; 

        for (int i = 0; i < n; ++i) {
            addRunning += diff[i];
            long long curr = power[i] + addRunning;
            if (curr < target) {
                long long need = target - curr;
                used += need;
                if (used > k) return false;

                int pos = min(n - 1, i + r);         
                int end = min(n - 1, pos + r);       
                addRunning += need;                  
                diff[end + 1] -= need;               
            }
        }
        return used <= k;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> pref(n+1, 0);
        for (int i = 0; i < n; ++i) pref[i+1] = pref[i] + stations[i];

        vector<long long> power(n, 0);
        for (int i = 0; i < n; ++i) {
            int L = max(0, i - r);
            int R = min(n - 1, i + r);
            power[i] = pref[R+1] - pref[L];
        }

        long long low = 0, high = (long long)1e18, ans = 0;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (canAchieve(mid, power, r, k, n)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long ans = 0 , count = 1;
        int n = prices.size();
        for(int i = 1; i < n; i++)
        {
            if(prices[i] - prices[i-1] == -1){
                count++;
            }
            else{
                ans += (count*(count+1))/2;
                count = 1;
            }
        }

        ans += (count *(count +1)/2);
        return ans;
    }
};
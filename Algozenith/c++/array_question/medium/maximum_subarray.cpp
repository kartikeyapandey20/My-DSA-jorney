#include<bits/stdc++.h>

using namespace std;

int maxSubArrayBrute(vector<int> &nums)
{
    int n = nums.size();
    int maximum = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            int sum = 0;

            for (int k = i; k <= j; k++)
            {
                sum = sum + nums[k];
            }

            maximum = max(sum , maximum);
        }
    }

    return maximum;

}

int maxSubArrayBetter(vector<int> &nums)
{
    int n = nums.size();
    int maximum = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = i; j < n; j++)
        {
            sum = sum + nums[j];
            maximum = max(sum , maximum);
        }
    }

    return maximum;

}

int main(){
    vector<int> nums = {1};

    int ans = maxSubArrayBrute(nums);

    cout << "(Brute)Maximum Sub Array as the sum of " << ans << endl;
    
    ans = maxSubArrayBetter(nums);

    cout << "(Better)Maximum Sub Array as the sum of " << ans << endl;
    return 0;
}
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

int maxSubArray(vector<int> &nums)
{
    int n = nums.size();
    int maximum = INT_MIN;
    int sum = 0;

    for (int i = 0; i < n; i++){
        sum += nums[i];

        if(sum > maximum){
            maximum = sum;
        }
        if(sum < 0){
            sum = 0;
        }
    }

    if(maximum < 0){
        maximum = 0;
    }
    return maximum;

}

// Not considering negative number as the maximum subarray
int main(){
    vector<int> nums = {1};

    int ans = maxSubArrayBrute(nums);

    cout << "(Brute)Maximum Sub Array as the sum of " << ans << endl;
    
    ans = maxSubArrayBetter(nums);

    cout << "(Better)Maximum Sub Array as the sum of " << ans << endl;

    ans = maxSubArray(nums);

    cout << "Maximum Sub Array as the sum of " << ans << endl;
    return 0;
}
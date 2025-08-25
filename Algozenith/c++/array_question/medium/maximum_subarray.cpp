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

            for (int k = i; k < j; k++)
            {
                sum = sum + nums[k];
            }

            maximum = max(sum , maximum);
        }
    }

    return maximum;

}

int main(){
    vector<int> nums = {-2,-3,4,-1,-2,1,5,-3};

    int ans = maxSubArrayBrute(nums);

    cout << "Maximum Sub Array as the sum of " << ans << endl;
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

void printArray(vector<int> nums)
{
    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    cout << endl;
}

vector<int> bruteRearrangeArray(vector<int> &nums){
    vector<int> positive;
    vector<int> negative;
    int n = nums.size();
    vector<int> ans;
    for(int  i = 0; i < n ; i++)
    {
        if(nums[i] > 0)
        {
            positive.push_back(nums[i]);
        }
        else{
            negative.push_back(nums[i]);
        }
    }

    for(int i = 0; i < n/2; i++)
    {
        ans.push_back(positive[i]);
        ans.push_back(negative[i]);
    }

    printArray(ans);
    return ans;
}

vector<int> betterRearrangeArray(vector<int> &nums){
    int n = nums.size();
    vector<int> ans(n, 0);
    int posIndex = 0 , negIndex = 1;
    for(int i = 0; i < n; i++){
        if(nums[i] < 0){
            ans[negIndex] = nums[i];
            negIndex+=2;
        }
        else{
            ans[posIndex] = nums[i];
            posIndex+=2;
        }
    }
    printArray(ans);
    return ans;
}
int main(){
    vector<int> array = {3,1,-2,-5,2,-4};
    vector<int> ans;

    ans = bruteRearrangeArray(array);
    ans = betterRearrangeArray(array);
    return 0;
}
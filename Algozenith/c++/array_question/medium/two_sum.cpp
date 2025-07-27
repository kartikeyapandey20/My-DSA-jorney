#include<bits/stdc++.h>

using namespace std;

// Brute Force
void twoSumBrute(vector<int> nums , int target){
    int firstIndex , secondIndex;
    for(int i = 0; i < nums.size(); i++)
    {
        for(int j =  i ; j < nums.size(); j++)
        {
            if(nums[i] + nums[j] == target)
            {
                firstIndex = i;
                secondIndex = j;
                break;
            }
        }
    }

    cout << "First value " << nums[firstIndex] << " At Index " << firstIndex <<endl;
    cout << "Second value " << nums[secondIndex] << " At Index " << secondIndex <<endl;
}

int main(){
    vector<int> nums = {2,4,6,2,7};
    twoSumBrute(nums,8);
    return 0;
}
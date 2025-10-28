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

// using stl
void stlNextPermutation(vector<int> &nums)
{
    next_permutation(nums.begin(),nums.end());
}

void nextPermutation(vector<int> &nums)
{
    int ind = -1;
    int n = nums.size();
    for(int i = n - 2; i >= 0;i--){
        if(nums[i] < nums[i+1])
        {
            ind = i;
            break;
        }
    }
    
    for(int i = n - 1; i > ind; i--){
        if(nums[i] > nums[ind]){
            swap(nums[i], nums[ind]);
            break;
        }
    }

    reverse(nums.begin() + ind + 1, nums.end());

    if(ind == -1){
        reverse(nums.begin(), nums.end());
    }
}
int main(){
    vector<int> nums =  {1,2,3};
    
    stlNextPermutation(nums);

    printArray(nums);

    nums =  {1,2,3};

    nextPermutation(nums);

    printArray(nums);

    return 0;

}
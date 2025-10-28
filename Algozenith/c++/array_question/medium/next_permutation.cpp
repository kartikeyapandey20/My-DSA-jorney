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
int main(){
    vector<int> nums =  {1,2,3};
    
    stlNextPermutation(nums);

    printArray(nums);
}
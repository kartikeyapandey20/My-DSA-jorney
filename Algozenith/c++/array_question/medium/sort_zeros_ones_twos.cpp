#include<bits/stdc++.h>

using namespace std;


void printArray(vector<int> nums)
{
    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}

void sortArrayBetter(vector<int> &nums)
{
    int countZero = 0;
    int countOne = 0;
    int countTwo = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i]==0)
        {
            countZero++;
        }
        if(nums[i]==1)
        {
            countOne++;
        }
        if(nums[i]==2)
        {
            countTwo++;
        }
    }

    for(int i = 0; i < countZero; i++)
    {
        nums[i] = 0;
    }

    for(int i = countZero ; i < countZero + countOne ; i++)
    {
        nums[i] = 1;
    }

    for(int i = countZero + countOne; i < countZero + countOne + countTwo; i++)
    {
        nums[i] = 2;
    }

    printArray(nums);

}

void sortArray(vector<int> &nums)
{
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while(mid <= high){
        if(nums[mid]==0)
        {
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }   
        else if(nums[mid]==1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid],nums[high]);
            high--;
        }
    }
    printArray(nums);

}
int main(){
    vector<int> nums = {0,1,2,0,1,2,1,0};
    // Better Solution
    sortArrayBetter(nums);
    // Optimal Solution
    sortArray(nums);
    return 0;
}
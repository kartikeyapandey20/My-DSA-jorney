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

int main(){
    vector<int> nums = {0,1,2,0,1,2,1,0};

    sortArrayBetter(nums);
    return 0;
}
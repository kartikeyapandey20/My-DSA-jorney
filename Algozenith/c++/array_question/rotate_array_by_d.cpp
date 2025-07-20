#include<bits/stdc++.h>

using namespace std;

void printArray(vector<int> nums)
{
    for(int i = 0; i < nums.size() ; i++)
    {
        cout << nums[i] << " ";
    }
}

// Brute force approach 
vector<int> rotateBrute(vector<int> &nums , int k){
    cout << "\nArray Before Rotation\n";
    printArray(nums);
    vector<int> temp(3);

    int d = k%nums.size();
    
    if(d==0){
        cout << "\nArray After "<< k <<"Rotation\n";
        printArray(nums);
        return nums;
    }

    // Temp store for the values that are going to rotated
    for(int i = 0 ; i < k; i++)
    {
        temp[i] = nums[i];
    }
    
    // Rotating array logic
    for(int i = d ; i < nums.size();i++)
    {
        nums[i - d] = nums[i];
    }
    
    int j = 0;
    // putting temp values
    for(int i = nums.size() - d; i < nums.size();i++)
    {
        nums[i] = temp[j]; 
        j++;
    }
    cout << "\nArray After Rotation\n";
    printArray(nums);
    return nums;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    rotateBrute(arr , 5);

}
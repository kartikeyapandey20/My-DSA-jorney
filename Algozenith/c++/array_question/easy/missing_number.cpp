#include<bits/stdc++.h>

using namespace std;

void missingNumberBrute(vector<int> arr , int n)
{
    int ans;
    for(int i = 1 ; i < n ; i++)
    {
        int flag = 0;
        for(int j = 0; j < n; j++)
        {
            if(arr[j] == i)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            ans = i;
            break;
        }
    }
    cout  << "\nThe Missing Number is " << ans;
}

void missingNumberBetter(vector<int> arr , int n)
{
    int ans;
    vector<int> hash(n+1,0);
    for(int i = 0; i < n; i++)
    {
        hash[arr[i]] = 1;
    }

    for(int i = 0; i < n; i++)
    {
        if(hash[i] == 0)
        {
            ans =  i;
            break;
        }
    }
    cout  << "\nThe Missing Number is " << ans;
}

void missingNumber(vector<int> arr , int N)
{
    int xor1 = 0 , xor2 = 0;
    for(int i = 0; i < N ; i++)
    {
        xor2 = xor2 ^ arr[i];
        xor1 = xor1 ^ (i+1);
    }
    int ans = xor1 ^ xor2;
    cout  << "\nThe Missing Number is " << ans;
}
int main(){
    vector<int> arr = {3,0,1};
    missingNumberBrute(arr,arr.size());
    missingNumberBetter(arr,arr.size());
    missingNumber(arr,arr.size());  
}
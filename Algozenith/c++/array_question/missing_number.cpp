#include<bits/stdc++.h>

using namespace std;

void missingNumberBrute(vector<int> arr , int n)
{
    int ans;
    for(int i = 1 ; i < n ; i++)
    {
        int flag = 0;
        for(int j = 0; j < n - 1; j++)
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
    cout  << "The Missing Number is " << ans;
}

int main(){
    vector<int> arr = {1,2,4,5};
    missingNumberBrute(arr,arr.size());

}
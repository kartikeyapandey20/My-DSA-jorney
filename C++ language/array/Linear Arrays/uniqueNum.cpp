#include<iostream>

using namespace std;

int main()
{
    int arr[7]={2,3,4,2,3,7,7};
    int ans=0;
    for(int i =0;i<7;i++)
    {
        ans = ans ^ arr[i];
    }
    cout<<ans<<" is the unique number in the array"<<endl;
}
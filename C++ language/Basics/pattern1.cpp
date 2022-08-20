#include<iostream>
using namespace std;
int main()
{
    int n;
    int count = 0;
    cout<<"enter value till you want to print pattern";
    cin>>n;
    for(int i =1 ;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<count<<" ";
            count++;
        }
        cout<<endl;
    }
    return 0;
}
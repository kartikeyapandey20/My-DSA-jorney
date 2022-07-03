#include<iostream>
using namespace std;
int main()
{
    int a;
    cout<<"enter a number for loop";
    cin>>a;
    for(int i =0;i<=a;i++)
    {
        for(int j =a;j>i;j--)
        {
            cout<<" ";
        }
        for(int j =0;j<i;j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}
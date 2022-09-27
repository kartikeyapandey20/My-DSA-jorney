#include<iostream>

using namespace std;

int fib(int n ){
    if(n==0)
    {
        return 0;
    }
    if(n==1){
        return 1;
    }

    int ans = fib(n-1) + fib(n-2);
    return ans;
}
int main()
{
    int fibnum;
    cout<<"Enter the fib num you want"<<endl;
    cin>>fibnum;

    int ans = fib(fibnum);

    cout<<ans<<"is the fibonacci num at "<<fibnum<<endl;
    return 0;
}

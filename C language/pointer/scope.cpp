#include<iostream>

using namespace std;

int main(){
    int i = 5;
    {
        int i=2;
        i++;
        cout<<i<<endl;
    }
    cout<<i<<endl;
    return 0;
}
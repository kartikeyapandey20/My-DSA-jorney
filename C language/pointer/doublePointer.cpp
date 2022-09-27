#include<iostream>

using namespace std;

int main(){

    int i =8;

    int * ptr = &i;

    int** ptr2 = &ptr;
    cout<<&ptr<<endl;
    cout<<ptr2<<endl;

    //PRINTING VALUR OF i 

    //this is using i
    cout<<"The value of i is "<<i<<endl;

    //this is using single pointer
    cout<<"The value of i is "<<*ptr<<endl;

    //this using double pointer
    cout<<"The value of i is "<<** ptr2<<endl;
  
    //PRINTING ADDRESS OF i

    cout<<"The address of i is "<<&i<<endl;
    cout<<"The address of i is "<<ptr<<endl;
    cout<<"The address of i is "<<*ptr2<<endl;
    return 0;
}
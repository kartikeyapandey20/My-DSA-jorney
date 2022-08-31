#include<iostream>

using namespace std;

void reverseString(char str[],int n){
    int start = 0;
    int end = n-2;
    while(start<=end){
        swap(str[start],str[end]);
        start++;
        end--;
    }
}
int main(){
    char str[11]={"helloWorld"};
    cout<<"The reversed string is : "<<str<<endl;
    reverseString(str,11);
    cout<<"The reversed string is : "<<str<<endl;
    return 0 ;
}
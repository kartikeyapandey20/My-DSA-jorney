#include<iostream>
#include<stack>

using namespace std;

int main(){
    stack<string> s;
    s.push("pandey");
    s.push("kartikeya");

    cout<<"Top element of the stack is "<<s.top()<<endl;

    s.pop();

    cout<<"Top element of the stack is "<<s.top()<<endl;

    cout<<"size of the stack is "<<s.size()<<endl;

    cout<<"stack is empty : "<<s.empty()<<endl;
    
    return 0;
}
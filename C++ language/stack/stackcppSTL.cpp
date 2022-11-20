#include<iostream>
#include<stack>

using namespace std;

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << "Top element of the stack " << s.top() << endl;

    if(s.empty()){
        cout << "The stack is empty" << endl;
    }
    else{
        cout << "The stack is not empty" << endl; 
    }
    return 0;
}
#include<iostream>

using namespace std;


class Stack{
    public:
        int * arr;
        int top;
        int size;

        Stack(int size)
        {
            this->top = -1;
            this->size = size;
            arr = new int[size];
        }
        bool isEmpty(){
            if(top > -1){
                return false;
            }
            else{
                return true;
            }
        }
        void push(int value)
        {
            if(size - top > 1){
                top++;
                cout << "After " << top << endl;
                arr[top] = value; 
            }
            else{
                cout << "Stack overflow" << endl;
            }
        }
        void pop(){
            if(top == -1){
                cout << "Stack underflow" << endl;
            }
            else {
                top--;
            }
        }

        int peek(){
            if(top > -1)
            {
                return arr[top];
            }
            else 
            {
                return -1;
            }
        }
};
int main(){
    Stack s(5);
    if(s.isEmpty()){
        cout << "Stack underflow" << endl;
    }
    else{
        cout << "elements are present in the stack" << endl;
    }
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    s.push(6);
    if(s.isEmpty()){
        cout << "Stack underflow" << endl;
    }
    else{
        cout << "elements are present in the stack" << endl;
    }

    cout << "The top of the stack is " << s.peek() << endl;

    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    cout << "The top of the stack is " << s.peek() << endl;
    return 0;
}
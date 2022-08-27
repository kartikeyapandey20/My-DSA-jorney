#include<iostream>
#include<queue>

using namespace std;

int main(){
    queue<string> q;

    q.push("hello");
    q.push("world");

    cout<<"size before pop"<<q.size()<<endl;

    cout<<"first element ->"<<q.front()<<endl;

    q.pop();

    cout<<"first element after poping -> "<<q.front()<<endl;

    cout<<"size after pop"<<q.size()<<endl;
    return 0;
}
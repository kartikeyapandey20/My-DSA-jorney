#include<iostream>
#include<deque>

using namespace std ;

int main()
{
    deque<int> d;
    //adding element from the back and the front of the array
    d.push_back(1);
    d.push_back(1);
    d.push_front(2);
    d.push_front(2);

    for(int i : d){
        cout<< i << " ";
    }cout<<endl;

    //deleting element from the front and the back of the array

    d.pop_back();
    d.pop_front();

    for(int i : d){
        cout<< i << " ";
    }cout<<endl;


    cout << "first element of the queue is " << d.front() << endl;
    cout << "last element of the queue is " << d.back() << endl;

    cout<<"is queue is empty "<<d.empty();

    cout<<"before erase"<<d.size();
    d.erase(d.begin(),d.begin()+1);
    cout<<"after erase"<<d.size();
    return 0;
}
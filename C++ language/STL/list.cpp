#include<iostream>
#include<list>

using namespace std;

int main(){
    list<int> l;
    l.push_back(1);
    l.push_front(2);
    l.push_back(1);
    l.push_front(2);

    for(int i : l){
        cout<<i<<" ";
    }cout<<endl;

    l.pop_back();
    l.pop_front();

    cout<<"before erase"<<endl;
    for(int i : l){
        cout<<i<<" ";
    }cout<<endl;

    cout<<"after erase"<<endl;
    l.erase(l.begin());
    for(int i : l){
        cout<<i<<" ";
    }cout<<endl;
    cout<<"size of the list is "<<l.size()<<endl;
    return 0;
}
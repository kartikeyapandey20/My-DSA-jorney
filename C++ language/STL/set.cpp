#include<iostream>
#include<set>

using namespace std;

int main(){
    set<int> s;
    // even thought we have inserted so many same element but in set all the values are distinct 
    // hence all the values will come only once
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(2);
    s.insert(1);
    s.insert(1);
    s.insert(3);
    s.insert(3);

    for(int i : s){
        cout<<i<<" ";
    }cout<<endl;

    //s.erase(s.begin());
    set<int>:: iterator it = s.begin();
    it++;
    s.erase(it);
    for(int i : s){
        cout<<i<<" ";
    }cout<<endl;
    //let us know if a particular number is present in the set or not

    cout<<"5 is present or not ->"<<s.count(5)<<endl;

    set<int>:: iterator itr = s.find(5);

    for(auto it= itr;it!=s.end();it++){
        cout<<*it<<" ";
    }cout<<endl;    
    
    return 0;
}
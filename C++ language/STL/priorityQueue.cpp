#include<iostream>
#include<queue>

using namespace std;

int main(){

    // max heap that is whenever you access the data from the priority queue it will always be greatest
    priority_queue<int> maxi;

    //mini heap that is whenever you access the data form the priority queue it will always be minimum
    priority_queue<int,vector<int>,greater<int> > mini;

    maxi.push(1);
    maxi.push(3);
    maxi.push(2);
    maxi.push(0);
    int n = maxi.size();
    for(int i = 0 ; i < n ; i++){
        cout<<maxi.top()<<" ";
        maxi.pop();
    }cout<<endl;

    mini.push(3);
    mini.push(1);
    mini.push(2);
    mini.push(0);
    int n = maxi.size();
    for(int i = 0 ; i < n ; i++){
        cout<<mini.top()<<" ";
        mini.pop();
    }cout<<endl;


    cout<<"is maxi is empty"<<maxi.empty()<<endl;
    cout<<"is mini is empty"<<mini.empty()<<endl;
    return 0;
}
#include<iostream>
#include<map>
using namespace std;

int main(){
    //in a map there is a key value pair meaing for particular key there will be value 
    //example 1-"hello" here 1 is key and hello is the value
    //if it is map it will in sorted order
    //if it is an unordered may it will not be in sorted order

    map<int,string> m;
    m[1] = "hello";
    m[2] = "hii";
    m[3] = "bello";

    m.insert({4,"world"});
    cout<<"before erase"<<endl;
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    cout<<"finding 13->"<<m.count(1)<<endl;
    m.erase(3);
    cout<<"after erase"<<endl;

    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    auto it = m.find(2);

    for(auto i = it ; i!= m.end();i++){
        cout<<(*i).first<<endl;
    }


    return 0;
}
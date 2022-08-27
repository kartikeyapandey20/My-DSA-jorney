#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    vector<int> ans;
    ans.push_back(1);
    ans.push_back(2);
    ans.push_back(3);
    ans.push_back(4);
    ans.push_back(5);

    cout<<"finding 4 -> "<<binary_search(ans.begin(),ans.end(),4)<<endl;

    cout<<"finding lower bound"<<lower_bound(ans.begin(),ans.end(),4)-ans.begin()<<endl;
    cout<<"finding lower bound"<<upper_bound(ans.begin(),ans.end(),4)-ans.begin()<<endl;

    string abcd = "abcd";
    reverse(abcd.begin(),abcd.end());
    cout<<"reverse of abcd -> "<<abcd<<endl;

    cout<<"before rotation"<<endl;

    for(int i : ans){
        cout<<i<<" ";
    }cout<<endl;

    rotate(ans.begin(),ans.begin()+1,ans.end());

    cout<<"after rotation"<<endl;

    for(int i : ans){
        cout<<i<<" ";
    }cout<<endl;
    
    return 0;
}
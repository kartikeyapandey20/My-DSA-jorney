#include<iostream>
#include<vector>

using namespace std;

void print(string str,int n){
    for(int i = 0 ; i < n ; i++){
        cout << str[i];
    }cout<<endl;
}
void solve(string str , string output , int index , vector<string> ans){
    if(index>=str.length()){
        print(output,output.length());
        if(output.length()> 0){
        ans.push_back(output);
        }
        return ;
    }

    //exclude
    solve(str,output,index+1,ans);

    //include
    char element = str[index];
    output.push_back(element);
    solve(str,output,index+1,ans);
        
}
vector<string> subSequence(string str){
    vector<string> ans;
    string output;
    int index = 0;
    solve(str,output,index ,ans);
    return ans;
}
int main(){
    string str = "abc";
    vector<string> ans ;
    ans = subSequence(str);
    return 0;
}
#include<iostream>
#include<vector>

using namespace std;

void print(vector<int> arr,int n){
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " " ;
    }cout<<endl;
}

void print2D(vector<vector<int>> arr,int n,int n2){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n2 ; j++){
            cout << arr[i][j] << " ";
        }cout<<endl;
    }
}

void solve(vector<int> nums,vector<int> output,int index , vector<vector<int>>& ans){
    //base case
    if(index >= nums.size()){
        print(output,output.size());
        ans.push_back(output);
        return ;
    }

    //exclude
    solve(nums,output,index+1,ans);
    //include
    int element = nums[index];
    output.push_back(element);
    solve(nums,output,index+1,ans);
}
vector<vector<int>> subset(vector<int> &nums){

    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(nums , output , index , ans);
    return ans;
}

int main(){
    vector<int> set = {1,2,3};
    vector<vector<int>> hello ;
    print(set,3);
    hello = subset(set);
    int row = hello.size();
    int col = hello[0].size();
    // print2D(hello,row,col);
    return 0;
}
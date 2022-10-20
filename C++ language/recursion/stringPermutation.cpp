#include<iostream>
#include<vector>

using namespace std;

void solve(vector<int> nums  , int index , vector<vector<int>> & ans ){
    if(index >= nums.size()){
        for(int i = 0 ; i < nums.size(); i++){
            cout << nums[i] ;
        }cout<<endl;
        ans.push_back(nums);
        return;
    }

    for(int i = index ; i < nums.size(); i++){
        swap(nums[index],nums[i]);
        solve(nums,index+1,ans);
        swap(nums[index],nums[i]);
    }
}
vector<vector<int>> permute(vector<int>& nums){
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0 ;
    solve(nums, index , ans);
}
int main(){
    vector<int> ans ={1,2,3};
    permute(ans);
    return 0;
}
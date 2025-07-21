#include<bits/stdc++.h>

using namespace std;

void printArray(vector<int> nums)
{
    for(int i = 0; i < nums.size() ; i++)
    {
        cout << nums[i] << " ";
    }
}

void union_of_sorted_array_brute(vector<int> arr1 , vector<int> arr2)
{
    set<int> st;

    for(int i = 0 ; i < arr1.size() ; i++)
    {
        st.insert(arr1[i]);
    }

    for(int i = 0 ; i < arr2.size() ; i++)
    {
        st.insert(arr2[i]);
    }

    vector<int>  temp;
    for(auto it : st)
    {
        temp.push_back(it);
    }    
    printArray(temp);
}
int main(){
    vector<int> arr1 = {1,1,2,3,4,5};
    vector<int> arr2 = {2,3,4,4,5,6};

    union_of_sorted_array_brute(arr1,arr2);

    return 0;
}
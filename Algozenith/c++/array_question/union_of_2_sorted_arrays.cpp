#include<bits/stdc++.h>

using namespace std;

void printArray(vector<int> nums)
{
    for(int i = 0; i < nums.size() ; i++)
    {
        cout << nums[i] << " ";
    }
}

// Brute Force Approach
void unionOfSortedArrayBrute(vector<int> arr1 , vector<int> arr2)
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

// Optimal Solution
void sortedArray(vector<int> a, vector<int> b)
{
    int n1 = a.size();
    int n2 = b.size();

    int i = 0;
    int j = 0;
    vector<int> unionArr;

    while(i < n1 && j < n2)
    {
        if(a[i] <= b[j])
        {
            if(unionArr.size() == 0 || unionArr.back() != a[i])
            {
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if(unionArr.size() == 0 || unionArr.back() != b[j])
            {
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }
    while(j < n2)
    {
            if(unionArr.size() == 0 || unionArr.back() != b[j])
            {
                unionArr.push_back(b[j]);
            }
            j++;
    }
    while(i < n1)
    {
        if(unionArr.size() == 0 || unionArr.back() != a[i])
            {
                unionArr.push_back(a[i]);
            }
            i++;
    }

    printArray(unionArr);
}

int main(){
    vector<int> arr1 = {1,1,2,3,4,5};
    vector<int> arr2 = {2,3,4,4,5,6};

    // Brute Force Solution
    unionOfSortedArrayBrute(arr1,arr2);
    // Optimal Solution
    sortedArray(arr1,arr2);
    return 0;
}
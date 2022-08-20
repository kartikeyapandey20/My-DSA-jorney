#include<iostream>
using namespace std;

int binarySearch(int arr[],int n , int key){
    int start = 0;
    int end = n-1;
    int mid = (start+end)/2;
    while(start<=end){
        if(arr[mid]== key){
            return mid;
        }
        else if (arr[mid]>key){
            end = mid-1;
        }
        else{
            start = mid +1;
        }
    mid = (start+end)/2;
    }
    return -1;

}
int main(){
    int even[]={1,2,3,4,5,6};
    int odd[]={1,2,3,4,5};
    int evenIndex = binarySearch(even,6,6);
    int oddIndex = binarySearch(odd,5,5);
    cout<<evenIndex<<endl;
    cout<<oddIndex<<endl;
    return 0;
}
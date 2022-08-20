#include <iostream>
using namespace std;

void reverseArray(int arr[], int size)
{
    int temp;
    for (int i = 0; i < size/2; i++)
    {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
    cout << "reversed array" << endl;

    for (int i=0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}

void reverseArray2(int arr[], int n)
{
    int start = 0;
    int end = n-1;
    while(start<=end)
    {
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    cout << "reversed array" << endl;

    for (int i=0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}
int main()
{
    int size;
    cout << "enter the size of the array" << endl;
    cin >> size;
    int arr[10];
    for (int i = 0; i < size; i++)
    {
        cout << "enter the element of the array" << endl;
        cin >> arr[i];
    }
    reverseArray(arr, size);
    reverseArray2(arr,size);
    return 0;
}
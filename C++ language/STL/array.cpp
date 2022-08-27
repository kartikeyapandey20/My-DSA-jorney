#include <iostream>
#include <array>
#include <vector>
using namespace std;
int main()
{
    // ARRAY IMPLEMENTATION OF STL IN C++
    int basic[3] = {1, 2, 3};
    array<int, 4> a = {1, 2, 3, 4};
    int size = a.size();
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << endl;
    }
    cout << "element at  2nd index is " << a.at(2) << endl;
    cout << "array is empty or not " << a.empty() << endl;
    cout << "first element of the array is " << a.front() << endl;
    cout << "last element of the array is " << a.back() << endl;


}
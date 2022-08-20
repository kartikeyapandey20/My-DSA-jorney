#include <iostream>
#include <array>
#include <vector>
using namespace std;
int main()
{
    // VECTOR IMPLEMENTATION OF THE STL IN C++
    // CREATING A VECTOR
    vector<int> v;
    // INITIAL SIZE OF EVERY VECTOR IS ZERO WE CAN CHECK THE SIZE OF THE VECTOR
    cout << "capacity->" << v.capacity() << endl;

    // WE CAN INSERT ELEMENT IS VECTOR USING PUSH BACK FUNCTION
    v.push_back(1);
    cout << "capacity->" << v.capacity() << endl;
    v.push_back(2);
    cout << "capacity->" << v.capacity() << endl;
    // HERE ITS CAPACITY WILL BE 4 AS IT INCREASE IT SIZE AS IT IS A DYANMIC ARRAY
    v.push_back(3);
    cout << "capacity-> " << v.capacity() << endl;
    cout<<"size of the vector is "<<v.size()<< endl;

    cout << "element at  2nd index is " << v.at(2) << endl;

    cout << "first element of the array is " << v.front() << endl;
    cout << "last element of the array is " << v.back() << endl;
    
    cout<<"before pop back"<<endl;
    for(int i : v)
    {
        cout<< i<<" ";
    }cout<<endl;

    v.pop_back();

    cout<<"after pop back"<<endl;
    for(int i : v)
    {
        cout<< i<<" ";
    }cout<<endl;

    cout<<"before clear size"<<v.size()<<endl;
    v.clear();

    cout<<"after clear size"<<v.size()<<endl;

    return 0;
}
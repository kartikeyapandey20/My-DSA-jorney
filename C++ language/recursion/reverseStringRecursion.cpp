#include<iostream>

using namespace std;

void reversedString(int start, int end ,string &str){

    if(start > end){
        return ;
    }
    else{
        swap(str[start],str[end]);
        start++;
        end--;
        reversedString(start,end,str);
    }
}
int main(){
    string name ;
    cout << "Enter your string get reverse of the string " << endl;
    cin>>name;
    reversedString(0,name.length()-1,name);
    cout<<name<<endl;
    return 0;
}
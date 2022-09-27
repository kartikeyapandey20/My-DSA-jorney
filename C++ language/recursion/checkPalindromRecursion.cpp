#include<iostream>

using namespace std;

bool checkPalindrome(string str,int i , int j){
    if(i > j){
        return true;
    }
    if(str[i]!=str[j] ){
        return false;
    }
    if(str[i]==str[j]){
        i++;
        j--;
        return checkPalindrome(str,i,j);
    }
    
}
int main(){
    string str = "hello";

    if(checkPalindrome(str,0,str.length()-1)){
        cout << "Is palindrome" << endl;
    }else{
        cout << "Not a palindrome" << endl;
    }
    return 0;
}
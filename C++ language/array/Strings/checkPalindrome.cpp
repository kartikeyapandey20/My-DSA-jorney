//In this question of palindrome you have to only consider alpha Numeric character otherwise 
//ignore the character

#include<iostream>

using namespace std;

char isLower(char ch){
    if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')){
        return ch;
    }
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool checkPalindrome(string s){
    int start = 0;
    int end = s.length()-1;
    while(start<end){
        if(!((s[start]>='a' && s[start]<='z') || (s[start]>='A' && s[start]<='Z') || (s[start]>='0' && s[start]<='9'))){
            start++;
        }
        else if(!((s[end]>='a' && s[end]<='z') || (s[end]>='A' && s[end]<='Z') || (s[end]>='0' && s[start]<='9'))){
            end--;
        }
        else if(isLower(s[start])!=isLower(s[end])){
            return 0;
        }
        else{
            start++;
            end--;
        }
    }
    return 1;
}

int main(){
    // This code is not working for this test case kindly please make imporvement if you cans
    string s ={"5?36@6?35"};
    // cout<<"enter a string"<<endl;
    // cin>>s;
    cout<<"your string is palindrome or not : "<<checkPalindrome(s);
    return 0;
}
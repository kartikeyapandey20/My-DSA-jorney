#include<iostream>

using namespace std;


char getMaxOccuCharacter(string s){
    int arr[26] = {0};

    for(int i = 0 ; i < s.length() ; i++ ){
        char ch = s[i];
        int number =0;
        // for lower case 
        if(ch >= 'a' && ch <= 's'){
            number = ch - 'a';
        }
        //for upper case
        else{
            number = ch - 'A' ;
        }

        arr[number]++;
    }
    int max = -1 , intAns =0;
    for(int i = 0 ; i < 26 ; i++){
        if(max < arr[i]){
            max = arr[i];
            intAns = i;
        }
    }
    char finalAns = 'a' + intAns;

    return finalAns;
}
int main(){
    string s;
    cin>>s;

    cout<<getMaxOccuCharacter(s)<<endl;
    return 0;
}
#include<iostream>

using namespace std;

void reachedHome(int src , int dest){

    //base case
    if(src==dest){
        cout<<"Pohoch gaya"<<endl;

        return;
    }
    src++;
    reachedHome(src,dest);
}
int main(){
    int dest = 10;
    int src = 1;

    reachedHome(src, dest);
    return 0;
}
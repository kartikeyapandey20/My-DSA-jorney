#include <stdio.h>
#include <stdlib.h>

    int visited[7]={0,0,0,0,0,0,0};
    int a[7][7]={
        {0,1,1,1,0,0,0},    //0
        {1,0,0,1,0,0,0},    //1
        {1,0,0,1,1,0,0},    //2
        {1,1,1,0,1,0,0},    //3
        {0,0,1,1,0,1,1},    //4
        {0,0,0,0,1,0,0},    //5
        {0,0,0,0,1,0,0},    //6
    };
void DFS(int i)
{
    int j;
    printf("%d ",i);
    visited[i]=1;
    for(int j = 0;j<7;j++)
    {
        if(a[i][j]=1 && !visited[j])
        {
            DFS(j);
        }
    }

}
int main()
{
    //DFS IMPLEMENTATION 
    DFS(0);
    return 0;
}
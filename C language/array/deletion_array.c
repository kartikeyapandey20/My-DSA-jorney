#include<stdio.h>
#include<string.h>
void arrayVisit(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d\n",arr[i]);
    }
}

int arrayDeletion(int arr[],int size,int index)
{
    for(int i=index;i<size;i++)
    {
        arr[i]=arr[i+1];
    }
    arr[size]='\0';
    return 1;
}
int main()
{
    int arr[10]={1,2,3,4,5,6,6};
    int size=7;
    arrayVisit(arr,size);
    arrayDeletion(arr,size,6);
    printf("hello\n");
    size-=1;
    arrayVisit(arr,size);
}
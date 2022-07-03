#include<stdio.h>
void display(int arr[],int n)
{
    printf("following array elements\n");
    for(int i=0;i<n;i++)
    {
        //this is know as traversing an array
        printf("%d\n",arr[i]);
    }
}
int insertArray(int arr[],int size,int element,int capacity,int index )
{
    if(size>= capacity)
    {
        printf("insertion failed due to size is greater the capacity of the array");
        return -1;
    }
    
    for(int i=size-1;i>=index;i--)
    {
        arr[i+1]=arr[i];

    }
    arr[index]= element;
    return  1;
    }


int main()
{
    int a[100]={7,8,12,27,88};
    int size=5 , element=34;
    display(a,size);
    insertArray(a,size=5,element,100,3);
    size+=1;
    display(a,size);
    return 0;
}
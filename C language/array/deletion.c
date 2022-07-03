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
void deletion(int arr[],int size,int index )
{
    
    for(int i=index;i<size-1;i++)
    {
        // code for deletion
        arr[i]=arr[i+1];

     }
     //bug in this code 
     printf("before the array %d\n",arr[index]);
    arr[index]= '\0';
     printf("after the array %d\n",arr[index]);

    }


int main()
{
    int a[10]={7,8,12,27,88};
    int size=5 ;
    display(a,size);
    deletion(a,size=5,4);
    size-=1;
     display(a,size);
    return 0;
}
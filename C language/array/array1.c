#include<stdio.h>
#include<stdlib.h>
typedef struct array
{
    int total_size;
    int used_size;
    int * ptr;
}arr;
void func(arr *a,int tsize,int usize)
{
    
//    (*a).total_size=tsize;
//    (*a).used_size=usize;
//    (*a).ptr=(int*)malloc(tsize*sizeof(int));

// alternate way to do above code
   a->total_size=tsize;
   a->used_size=usize;
   a->ptr=(int*)malloc(tsize*sizeof(int));
}
void arrelement(arr *a)
{
    int n;
    for(int i=0;i<a->used_size;i++)
    {
        printf("\nenter the element %d",i);
        // scanf("%d",((*a).ptr)[i]); why not working
        scanf("%d",&n);
        (a->ptr)[i]=n;
    }
}
void show(arr *a)
{
    for(int i=0;i<a->used_size;i++)
    {
        printf("\n%d\n",(a->ptr)[i]);
    }
}
void main()
{
    arr marks;
    func(&marks,10,2);
    printf("taking user input");
    arrelement(&marks);
    printf("printing the values of te array");
    show(&marks);

}
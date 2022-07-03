#include<stdio.h>
#include<stdlib.h>
// structure for stack with size,top and array pointer
typedef struct stack
{
    int size;
    int top;
    int *arr;
}stack;

//function for checking whether the stack is full or not
int isFull(stack * ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

// function for checking whether the stack is empty or not

int isEmpty(stack * ptr)
{
    if(ptr->top==(-1))
    {
        return 1;
    }
    else{
        return 0;
    }
}

//function for adding values in the stack 
void pushInStack(stack * ptr, int value)
{
    //this block is defined so that if stack is full it will be returned
    if(isFull(ptr))
    {
       printf("Stack overflow ! cannot push %d in the stack\n",value);
       
    }

    // following else block will add values is the stack
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=value; 
    }
}

// fucntion for removing top most value form the stack as one cannot remove  any random value from the
// stack and can only remove top value 
int popInStack(stack *ptr)
{
    int value;
    if(isEmpty(ptr))
    {
        printf("stack is underflowed please add values to it");
    }
    else
    {
        value =ptr->arr[ptr->top]; 
        ptr->top--;
        return value;
    }
}

//function for seeking any value at particular postiion in stack
int peekInStack(stack * ptr, int i)
{
    int arrInd= ptr->top - i+1;
    if(arrInd<0){
        printf("invalid postion entered for the stack");
    }
    else{
        return ptr->arr[arrInd]; 
    }
}
//function for getting top value in the stack
int stackTop(stack * ptr){
    if(isEmpty(ptr))
    {
        printf("stack underflowes");
    }
    else{
        return ptr->arr[ptr->top];
    }
}

//function for getting bottom value of the stack
int stackBottom(stack * ptr){
    if(isEmpty(ptr))
    {
        printf("stack underflowes");
    }
    else{
        return ptr->arr[0];
    }
}

int main()
{
    //making stack * pointer
    stack * sp=(stack *)malloc(sizeof(stack));
    sp->size=10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("stack has been created successfully\n");
    // checking the stack before the adding the values
    printf("Before pushing isFull :%d\n",isFull(sp));
    printf("Before pushing isEmpty :%d\n",isEmpty(sp));
    
    pushInStack(sp, 1);
    pushInStack(sp, 2);
    pushInStack(sp, 3);
    pushInStack(sp, 4);
    pushInStack(sp, 5);
    pushInStack(sp, 6);
    pushInStack(sp, 7);
    pushInStack(sp, 8);
    pushInStack(sp, 9);
    pushInStack(sp, 10);// stack is full over here
    pushInStack(sp, 11);// stack is overflowed over here as the size of the stack 10 

    //checking the stack after adding the values
    printf("After pushing isFull :%d\n",isFull(sp));
    printf("After pushing isEmpty :%d\n",isEmpty(sp));

    printf("Poped %d element from the stack\n",popInStack(sp));
    //printing values from the stack 
    for(int j =1;j<=sp->top+1;j++)
    {
    printf("the value at position %d is %d\n",j,peekInStack(sp,j));
    }
    printf("The top value of the stack is %d\n",stackTop(sp));
    printf("The bottom value of the stack is %d\n",stackBottom(sp));
    return 0;
}
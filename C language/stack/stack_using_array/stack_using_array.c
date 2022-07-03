#include<stdio.h>
#include<stdlib.h>

typedef struct  stack
{
    int size;
    int top;
    int *arr;
}stack;

int isEmpty(stack *s)
{
    if(s->top==(-1))
    {
        printf("Your stack is empty");
        return 1;
    }
    else{
        printf("your stack is not empty");
        return 0;
    }
}

int isFull(stack *s)
{
    if(s->top==(s->size-1))
    {
        printf("your stack full");
        return 1;
    }
    else{
        printf("Your stack is not full ");
        return 0;
    }
}

int pushInStack(stack *s,int value)
{
    if(isFull)
    {
        printf("stack overflow");
    }
    else{
        s->top=s->top++;
        s->arr[s->top]=value;
    }
}
int main()
{
    // this one method of declaring the stack 
    // stack s;
    // s.size=80;
    // s.top=-1;
    // s.arr= (int *)malloc(s.size * sizeof(int));

    int  m;
    stack *s;
    s->size=80;
    s->top= (-1);
    s->arr=(int *)malloc(s->size *( sizeof(int)));
    isEmpty(s);
    isFull(s);
    
    return 0;
}
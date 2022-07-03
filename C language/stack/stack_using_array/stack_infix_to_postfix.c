#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// structure for stack with size,top and array pointer
typedef struct stack
{
    int size;
    int top;
    char *arr;
} stack;

// function for checking whether the stack is full or not
int isFull(stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// function for checking whether the stack is empty or not

int isEmpty(stack *ptr)
{
    if (ptr->top == (-1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// function for adding values in the stack
void pushInStack(stack *ptr, char value)
{
    // this block is defined so that if stack is full it will be returned
    if (isFull(ptr))
    {
        printf("Stack overflow ! cannot push %c in the stack\n", value);
    }

    // following else block will add values is the stack
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

// fucntion for removing top most value form the stack as one cannot remove  any random value from the
// stack and can only remove top value
int popInStack(stack *ptr)
{
    char value;
    if (isEmpty(ptr))
    {
        printf("stack is underflowed please add values to it");
    }
    else
    {
        value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int stackTop(stack *ptr)
{
    return ptr->arr[ptr->top];
    
}

int precedence(char ch)
{
    if(ch=='*' || ch=='/')
    {
        return 3;
    }
    else if(ch=='+' ||  ch =='-') 
    {
        return 2;
    }
    else
    {
        return 0;
    }

}

int isOperator(char ch)
{
    if(ch=='*' || ch=='/' || ch=='+' || ch=='-')
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}
char *infixToPostfix(char *infix)
{
    stack *sp=(stack *)malloc(sizeof(stack));
    sp->size = 100 ;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc(strlen(infix) + 1 * sizeof(char));
    int i = 0; // track infix traversal
    int j = 0; // track postfix addtion
    while (infix[i] != '\0')
    {
        if(!isOperator(infix[i]))
        {
            postfix[j]=infix[i];
            j++;
            i++;
        }
        else
        {
            if(precedence(infix [i])>precedence(stackTop(sp)))
            {
                pushInStack(sp,infix[i]);
                i++;
            }
            else{
                postfix[j]=popInStack(sp);
                j++;  
            }

        }
    }
    while (!isEmpty(sp))
    {
        postfix[j]=popInStack(sp);
        j++; 
    }
    postfix[j]='\0';
    return postfix; 
    
}
int main()
{
    char *infix = "a-d+t/6";
    printf("infix %s to postfix is %s",infix,infixToPostfix(infix));
    return 0;
}
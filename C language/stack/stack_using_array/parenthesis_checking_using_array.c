#include <stdio.h>
#include <stdlib.h>
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

int parenthesisMatch(char *exp)
{
    stack *sp;
    sp->size = 80;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            pushInStack(sp, exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            popInStack(sp);
        }
    }
    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


//my method for poping in stack for multiple parenthesis checking

int multipleParenthesisCheck1(char *exp)
{
    stack *sp;
    sp->size = 80;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{'|| exp[i] == '[')
        {
            pushInStack(sp, exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            else if(sp->arr[sp->top]=='('){
                popInStack(sp);
            }
            else{
                printf("mistake in ( ");
            }
        }
        else if (exp[i] == '}')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            else if(sp->arr[sp->top]=='{'){
                popInStack(sp);
            }
            else{
                printf("mistake in ( ");
            }
        }
        else if (exp[i] == ']')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            else if(sp->arr[sp->top]=='['){
                popInStack(sp);
            }
            else{
                printf("mistake in ( ");
            }
        }
    }
    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//this function check that for every opening bracket there is a closing bracket  
//in the stack according to codeWithHarry method
int match(char a, char b)
{
    if(a=='(' && b==')')
    {
        return 1;
    }
    if(a=='{' && b=='}')
    {
        return 1;
    }
    if(a=='[' && b==']')
    {
        return 1;
    }
    return 0;
}


//codeWithHarry method for checking multiple parenthesis checking
int multipleParenthesischeck2(char * exp)
{
    stack *sp;
    sp->size = 80;
    sp->top = -1;
    int popped_ch;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{'|| exp[i] == '[')
        {
            pushInStack(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}'|| exp[i] == ']')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            popped_ch= popInStack(sp);
            if(!match(popped_ch,exp[i]))
            {
                return 0;
            }
        }
    }
    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char *ptr = "{8*(9)}";

    //if else statement for checking single parenthesis statment
    if (parenthesisMatch(ptr))
    {
        printf("parenthesis is matching\n");
    }
    else
    {
        printf("parenthesis is not matching\n");
    }
    //if else statement for checking mutilple parenthesis
    if(multipleParenthesisCheck1(ptr))
    {
        printf("parenthesis is matching\n");
    }
    else
    {
        printf("parenthesis is not matching\n");
    }

    if(multipleParenthesischeck2(ptr))
    {
        printf("parenthesis is matching\n");
    }
    else
    {
        printf("parenthesis is not matching\n");
    }

    return 0;
}
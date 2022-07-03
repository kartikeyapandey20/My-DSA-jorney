#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

//here top is defined as global variable so that we do not have to deference it while poping the value
// Node *top = NULL;

//this function is defined so that we can use pop wihtout deference our top variable
//as if pointer concept is not clear it can be done by this method

// int pop(Node * tp)
// {
//     if(isEmpty(tp))
//     {
//         printf("Stack underflowed");
//     }
//     else{
//         Node * ptr = tp;
//         top=(tp)->next;
//         int x = ptr->data;
//         free(ptr);
//         return x ;
//     }
// }
void linkedListTraversal(Node *top)
{       
    int i=0;
    while (top != NULL)
    {
        printf("%d->", top->data);
       top = top->next;
       if(i>5)
       {
        break;
       }
       i++;
    }
    printf("NULL");
    printf("\n");
}
// here ptr is given as an argument so that if the top of the stack made with linked list
// and node is null as that means that the dynamically allocated memory is empty hence the stack is
// empty
int isEmpty(Node *ptr)
{
    if (ptr == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// if i am unable to create a new node in the stack hence my memory is full
// because if i try to make new node and my memory is exhausted hence memory is not available
// hence the stack is full
int isFull(Node *ptr)
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// this is a function for adding node in the stack
Node *push(Node *top, int x)
{
    if (isFull(top))
    {
        printf("Stack overflow\n");
    }
    else
    {   
        Node *ptr;
        ptr = (Node *)malloc(sizeof(Node));
        ptr->data = x;
        ptr->next=top;
        top = ptr;
        return top;
    }
}

int pop(Node ** top)
{
    if(isEmpty(*top))
    {
        printf("Stack underflowed");
    }
    else{
        Node * ptr = *top;
        *top=(*top)->next;
        int x = ptr->data;
        free(ptr);
        return x ;
    }
}
int peek(Node * top,int position)
{
    Node * ptr =top;
    for(int i =1; (i<=position && ptr!=NULL);i++)
    {
        printf("%d at posiition %d\n",ptr->data,i);
        ptr=ptr->next;
    }
    if(ptr!=NULL)
    {
        return ptr->data;
    }
    else{
        return -1;
    }
}
int stackTop(Node * top)
{
    Node * ptr= top;
    printf("%d",ptr->data);
    return ptr->data;
}
int stackBottom(Node * top)
{
    Node * ptr=top;
    while(ptr!=NULL)
    {
        ptr=ptr->next;
    }
    printf("%d",ptr->data);
    return ptr->data;
}
int main()
{
    Node *top = NULL;
    top=push(top, 1);
    top=push(top, 2);
    top=push(top, 3);
    top=push(top, 4);
    linkedListTraversal(top);


    int element= pop(&top);
    printf("Popped element is %d\n",element);
    linkedListTraversal(top);
    peek(top,1);
    return 0;
}
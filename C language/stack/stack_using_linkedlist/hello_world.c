#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * next;
};

// if i am unable to create a new node in the stack hence my memory is full
// because if i try to make new node and my memory is exhausted hence memory is not available
// hence the stack is full
int isFull(struct Node * top)
{
    struct Node * p=(struct Node *)malloc(sizeof (struct Node));
    if(p==NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
}

// here ptr is given as an argument so that if the top of the stack made with linked list
// and node is null as that means that the dynamically allocated memory is empty hence the stack is
// empty

int isEmpty(struct Node * top)
{
    if(top==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

// this is a function for adding node in the stack
struct Node * push(struct Node * top,int x)
{
    if(isFull(top))
    {
        printf("Stack overflow");
    }
    else{
        struct Node * n=(struct Node *)malloc(sizeof(struct Node));
        n->data=x;
        n->next=top;
        top = n;
        return top;
    }
}

// function for traversing linkedlist
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        printf("|\n");
        printf("V\n");
        ptr = ptr->next;
    }
    printf("NULL");
    printf("\n");
}
int main()
{
    struct Node * top=NULL;
    top=push(top, 78);
    top=push(top, 78);
    linkedListTraversal(top);
    return 0;
}
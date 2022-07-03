#include<stdio.h>
#include<stdlib.h>
typedef struct  Node
{
    int data;
    struct Node *next;
    
}Node;
//defining a function for travesing a linkedlist

void linkedListTraversal(Node * ptr)
{
    while(ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL");
}

int main()
{
    Node *head;
    Node *second;
    Node *thrid;

    // allocationg memory in heap using linked list
    head=(Node*)malloc(sizeof(Node));
    second=(Node*)malloc(sizeof(Node));
    thrid=(Node*)malloc(sizeof(Node));
    
//making a linked list using structure

    //here first and second node is connected 

    head->data=7;
    head->next=second;

    //here second and third node is connected

    second->data=8;
    second->next=thrid;

    //here third node is terminated after getting and its next is pointing and next

    thrid->data=9;
    thrid->next=NULL;

    //calling linkedListTraversal function
    linkedListTraversal(head);


}
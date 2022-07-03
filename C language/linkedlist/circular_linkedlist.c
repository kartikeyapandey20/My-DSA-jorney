#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
    
}Node;
//defining a function for travesing a linkedlist

void linkedListTraversal(Node * head)
{
    Node * ptr= head;
    do{
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
printf("\n");     
}

Node * insertionAtHead(Node * head,int element)
{
    Node * ptr=(Node*)malloc(sizeof(Node));
    ptr->data=element;
    Node * q=head->next;
    do{
        q=q->next;
    }while(q->next!=head);
    q->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
}

int main()
{
    Node *head;
    Node *second;
    Node *thrid;
    Node *fourth;

    // allocationg memory in heap using linked list
    head=(Node*)malloc(sizeof(Node));
    second=(Node*)malloc(sizeof(Node));
    thrid=(Node*)malloc(sizeof(Node));
    fourth=(Node*)malloc(sizeof(Node));
    
//making a linked list using structure

    //here first and second node is connected 

    head->data=7;
    head->next=second;

    //here second and third node is connected

    second->data=8;
    second->next=thrid;

    //here third and fourth node is connected

    thrid->data=9;
    thrid->next=fourth;

    //here fourth node is pointing at the head so that we can form circular linkedlist
    fourth->data=3;
    fourth->next=head;

    
    //calling linkedListTraversal function
    printf("circular linkedlist before insertion\n");
    linkedListTraversal(head);
    head=insertionAtHead(head,4);
    printf("circular linkedlist after insertion\n");
    linkedListTraversal(head);
}
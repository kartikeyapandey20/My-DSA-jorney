#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;

} Node;

// function for traversing linkedlist
void linkedListTraversal(Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
    printf("\n");
}

// function for inserting node as head or starting point of linked list
Node *insertNodeAtHead(Node *head, int data)
{
    Node *ptr;
    ptr = (Node *)malloc(sizeof(Node));
    ptr->next = head;
    ptr->data = data;
}

// function for inserting node at the end of the linkedlist
Node *insertNodeAtEnd(Node *head, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
}

// function for inserting node at a index in linked list
Node *insertNodeAtIndex(Node *head, int data, int index)
{
    Node *ptr;
    ptr = (Node *)malloc(sizeof(Node));
    Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

// function for inserting node at after a node in a linked list
Node *insertNodeAfterNode(Node *head, Node *prevNode, int data)
{
    Node *ptr;
    ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

int main()
{
    Node *head;
    Node *second;
    Node *thrid;
    Node *fourth;

    // allocationg memory in heap using linked list
    head = (Node *)malloc(sizeof(Node));
    second = (Node *)malloc(sizeof(Node));
    thrid = (Node *)malloc(sizeof(Node));
    fourth = (Node *)malloc(sizeof(Node));

    // making a linked list using structure

    // here first and second node is connected

    head->data = 7;
    head->next = second;

    // here second and third node is connected

    second->data = 8;
    second->next = thrid;

    // here third and fourth node is connected
    thrid->data = 9;
    thrid->next = fourth;

    // here fourth node is terminated after getting and its next is pointing and next
    fourth->data = 11;
    fourth->next = NULL;

    // calling linkedListTraversal function
    printf("Before inserting in the linkedlist\n");
    linkedListTraversal(head);

    // for inserting node at the begining
        printf("after inserting in the linkedlist\n");
        head=insertNodeAtHead(head,1);
        linkedListTraversal(head);

    // for inserting node in between
        //  printf("after inserting in the linkedlist\n");
        //  insertNodeAtIndex(head,12,1);
        //  linkedListTraversal(head);

    // for inserting at the end
        // printf("after inserting in the linkedlist\n");
        // insertNodeAtEnd(head, 12);
        // linkedListTraversal(head);
    // for inserting after node
        // printf("after inserting in the linkedlist\n");
        // head = insertNodeAfterNode(head, second, 12);
        // linkedListTraversal(head);
}
#include<stdio.h>
#include<stdlib.h>


typedef struct Node
{
    int data;
    struct Node * next;
    
}Node;
//HERE FRONT AND REAR IS GLOBALLY DECLARED SO THAT WE CAN ACCESS THEM GLOBALLY
//WE CAN ALSO DO THIS WITH HELP OF POINTER TO POINTER ON FRONT AND REAR
Node*f=NULL;
Node*r=NULL;

//FUCNTION FOR QUEUE TRAVERSAL
void queueTraversal()
{
    Node * n=f;
    while (n!=NULL)
    {
        printf("%d->",n->data);
        n=n->next;
    }
    printf("NULL\n");
    
}

//FUNCTION FOR ADDING VALUES TO THE QUEUE
void enqueue(int val)
{
    Node * ptr = (Node*)malloc(sizeof(Node));
    //IT FOR CHECKING THAT QUEUE IS FULL OR NOT
    if(ptr==NULL)
    {
        printf("Queue is overflowed");
    }
    else
    {
        ptr->data=val;
        ptr->next=NULL;
        //ITS A SPECIAL CASE IF THE FRONT AND REAR BOTH ARE POINTING NULL FROM THE STARTING
        //HENCE WHILE ADDING VALUES IT WILL BECOME FRONT AND REAR
        if(f==NULL)
        {
            f=ptr;
            r=ptr;
        }
        else
        {
            r->next=ptr;
            r=ptr;
        }
    }
}
//FUNCTION FOR REMOVING VALUES FORM THE QUEUE
int dequeue()
{
    int val=-1;
    Node * ptr=(Node*)malloc(sizeof(Node));
    ptr=f;
    if(f==NULL)
    {
        printf("queue is empty");
    }  
    else{
        f=f->next;
        val=ptr->data;
        free(ptr);
    }
  return val;

}
int main()
{

    queueTraversal();
    enqueue(1);
    enqueue(2);
    enqueue(3);
    queueTraversal();
    dequeue();
    queueTraversal();
 //   printf("%d",dequeue(f));
}
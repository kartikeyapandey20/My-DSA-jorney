#include <stdio.h>
#include <stdlib.h>
//STRUCTURE FOR QUEUE
typedef struct circularQueue
{
    int size;
    int f;
    int r;
    int *arr;
}circularQueue;
//FUNCTION FOR CHECHKING IF QUEUE IS EMPTY OR NOT
int isEmpty(circularQueue*q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//FUNCTION FOR CHECHKING IF QUEUE IS FULL OR NOT
int isFull(circularQueue *q)
{
    if ((q->r+1)%q->size==q->f)
    {
        return 1;
    }  
    else
    {
        return 0;
    }
}
//FUCNTION FOR ADDING VALUES IN THE QUEUE
int enqueue(circularQueue *q, int val)
{
    if (isFull(q))
    {
        printf("queue overflow");
    }
    else
    {
        // HERE WE ARE INCREASING THE VALUE OF THE r AS WE WANT TO INSERT VALE OF THE ARE
        //HERE WE HAVE USED % FOR CIRCULAR INCREMENT SO THAT WE CAN ADD AND REMOVE VALUES 
        //ACCORDING TO OUR NEED
        q->r=(q->r+1)% q->size ;
        //AFTER INCREASING WE ARE USING AS INDEX OF THE ARRAY TO INSERT INTO THE ARRAY
        q->arr[q->r] = val;
        printf("element added in queue %d\n",val);
        return q->arr[q->r];
    }
}

int queueTraversal(circularQueue *q)
{
    int i = q->f;
    if (isFull(q))
    {
        return 0;
    }
    else
    {
        while (i <= q->r)
        {
            printf("%d\n", q->arr[i]);
            i++;
        }
    }
}

//FUCNTION FOR REMOVING VALUE FROM THE FRONT SIDE AS QUEUE FOLLOWS FIFO CONCEPT
int dequeue(circularQueue*q)
{
    int a = 0;
    if (isEmpty(q))
    {
        return 0;
    }
    else
    {
        //HERE WE ARE INCREAING VALUE OF THE FRONT POINTER (P.S THIS IS NOT A POINTER IT  IS USED FOR INDEX)
        //HERE WE HAVE USE % FOR CIRCULAR INCREMENT FOR THE FRONT SIDE HENCE 
        //HERE FRONT f =0 AS INITIAL VALUE CANNOT BE 1 AS THE -1 CANNOT WORK FOR THE CIRCULAR INCREMENT
        q->f=(q->f+1)% q->size ;
        a = q->arr[q->f];

    }
    return a;
}

int main()          
{
    circularQueue *q = (circularQueue *)malloc(sizeof(circularQueue));
    q->size = 10;
    q->f = 0;
    q->r = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));
    // printf("empty queue returns:%d\n",isEmpty(q));
    // printf("full queue returns:%d\n",isFull(q));
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    printf("dequeueing element %d\n", dequeue(q));
    printf("dequeueing element %d\n", dequeue(q));
    printf("dequeueing element %d\n", dequeue(q));

    enqueue(q, 11);
    enqueue(q, 12);
    enqueue(q, 13);
    if(isEmpty(q))
    {
        printf("queue is empty");
    }
    if(isFull(q))
    {
        printf("queue is full");
    }
    return 0;
}
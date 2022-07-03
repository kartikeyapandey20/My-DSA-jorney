#include <stdio.h>
#include <stdlib.h>
//STRUCTURE FOR QUEUE
struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};
//FUNCTION FOR CHECHKING IF QUEUE IS EMPTY OR NOT
int isEmpty(struct queue *q)
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
int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//FUCNTION FOR ADDING VALUES IN THE QUEUE
int enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("queue overflow");
    }
    else
    {
        // HERE WE ARE INCREASING THE VALUE OF THE r AS WE WANT TO INSERT VALE OF THE ARE
        q->r++;
        //AFTER INCREASING WE ARE USING AS INDEX OF THE ARRAY TO INSERT INTO THE ARRAY
        q->arr[q->r] = val;
        return q->arr[q->r];
    }
}

int queueTraversal(struct queue *q)
{
    // struct queue *a=q;
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
int dequeue(struct queue *q)
{
    int a = 0;
    if (isEmpty(q))
    {
        return 0;
    }
    else
    {
        //HERE WE ARE INCREAING VALUE OF THE FRONT POINTER (P.S THIS IS NOT A POINTER IT  IS USED FOR INDEX)
        q->f++;
        a = q->arr[q->f];
        // free(q);
    }
    return a;
}

int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 10;
    q->f = -1;
    q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
    // printf("empty queue returns:%d\n",isEmpty(q));
    // printf("full queue returns:%d\n",isFull(q));
    enqueue(q, 12);
    enqueue(q, 1);
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    return 0;
}
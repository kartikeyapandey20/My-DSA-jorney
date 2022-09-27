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
    }
    return a;
}

int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 400;
    q->f = 0;
    q->r = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));

    //BFS IMPLEMENTATION 
    
    int  node;
    int i =0;
    int visited[7]={0,0,0,0,0,0,0};
    int a[7][7]={
        {0,1,1,1,0,0,0},    //0
        {1,0,0,1,0,0,0},    //1
        {1,0,0,1,1,0,0},    //2
        {1,1,1,0,1,0,0},    //3
        {0,0,1,1,0,1,1},    //4
        {0,0,0,0,1,0,0},    //5
        {0,0,0,0,1,0,0},    //6
    };
    printf("%d ",i);
    visited[i]=1;
    enqueue(q,i);//ENQUEUING i FOR EXLORATION
    while(!isEmpty(q))
    {
        int node = dequeue(q);
        for(int j =0 ; j < 7 ; j++)
        {
            if(a[node][j]==1 && visited[j]==0)
            {
                printf("%d ",j);
                visited[j]=1;
                enqueue(q,j);
            }
        }
    }

    return 0;
}
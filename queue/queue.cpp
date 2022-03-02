#include <iostream>

using namespace std;

class queue
{
public:
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}
int isEmpty(queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(queue *q, int val)
{
    if (isFull(q))
    {
        printf("This Queue is full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
        printf("Enqued element: %d\n", val);
    }
}

int dequeue(queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This Queue is empty\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    queue *q = new queue();
    q->size = 8;
    q->f = q->r = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue(q, 12);

    enqueue(q, 1);
    printf("Dequeuing element %d\n", dequeue(q));
    printf("Dequeuing element %d\n", dequeue(q));
    // printf("Dequeuing element %d\n", dequeue(q));
    enqueue(q, 45);
    enqueue(q, 16);
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    if (isFull(q))
    {
        printf("Queue is full\n");
    }
}
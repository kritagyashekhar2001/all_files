#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;
};
node *f = NULL;
node *r = NULL;

void linkedListTraversal(node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val)
{
    node *n = new node();
    if (n == NULL)
    {
        cout << "queue is full";
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}
int dequeue()
{
    int a = -1;
    node *n = f;
    if (f == NULL)
    {
        cout << "queue is empty";
    }
    else
    {
        f = f->next;
        a = n->data;
        free(n);
    }
    return a;
}
int main()
{
    // linkedListTraversal(f);
    // printf("Dequeuing element %d\n", dequeue());
    enqueue(34);
    enqueue(4);
    enqueue(7);
    enqueue(17);
    linkedListTraversal(f);
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    // printf("Dequeuing element %d\n", dequeue());
    // printf("Dequeuing element %d\n", dequeue());
    linkedListTraversal(f);
    return 0;
}
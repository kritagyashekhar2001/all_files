#include <iostream>
#include <stdlib.h>

using namespace std;

class node
{
public:
    int data;
    node *next;
};
void linkedListTraversal(node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
int isEmpty(node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(node *top)
{
    node *p = new node();
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
class node *push(node *top, int data)
{
    if (isFull(top))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        node *n = new node();

        n->data = data;
        n->next = top;

        top = n;
        return top;
    }
}

int pop(node *top)
{
    if (isEmpty(top))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        node *n = top;
        top = top->next;
        int x = n->data;
        free(n);
        return x;
    }
}
int main()
{
    class node *top = NULL;

    top = push(top, 5);
    top = push(top, 78);
    top = push(top, 7);
    top = push(top, 8);
    int element = pop(top);
    printf("Popped element is %d\n", element);
    linkedListTraversal(top);
    return 0;
}
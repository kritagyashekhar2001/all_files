#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

node *merge(node *p, node *q, node *sorting)
{
    node *newhead = NULL;
    if (p == NULL)
    {
        return q;
    }
    if (q == NULL)
    {
        return p;
    }
    if (p && q)
    {
        if (p->data <= q->data)
        {
            sorting = p;
            p = sorting->next;
        }
        else
        {
            sorting = q;
            q = sorting->next;
        }
    }
    newhead = sorting;
    while (p && q)
    {
        if (p->data <= q->data)
        {
            sorting->next = p;
            sorting = p;
            p = sorting->next;
        }
        else
        {
            sorting->next = q;
            sorting = q;
            q = sorting->next;
        }
    }
    if (p == NULL)
    {
        sorting->next = q;
    }
    if (q == NULL)
    {
        sorting->next = p;
    }

    return newhead;
}
void push(node **head_ref, int new_data)
{

    node *new_node = new node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void linkedListTraversal(node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{

    node *res = NULL;
    node *a = NULL;
    node *b = NULL;
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    linkedListTraversal(a);

    push(&b, 20);
    push(&b, 3);
    push(&b, 2);
    linkedListTraversal(b);
    cout << "Merged Linked List is: \n";
    node *res1 = merge(a, b, res);
    linkedListTraversal(res1);

    return 0;
}
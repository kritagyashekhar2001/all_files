#include <iostream>

using namespace std;
class node
{
public:
    int data;
    node *next;
};

void traversal(node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

void insert(node **head, int data)
{
    node *ptr = new node();
    ptr->next = *head;
    ptr->data = data;

    *head = ptr;
}

void reverse(node **head)
{
    node *prev;
    node *next;
    node *current;

    current = *head;
    prev = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main()
{
    node *head = new node();
    node *second = new node();
    node *third = new node();

    head->data = 7;
    head->next = second;

    second->data = 9;
    second->next = third;

    third->data = 5;
    third->next = NULL;

    // traversal(head);
    // insert(&head, 2);
    reverse(&head);
    cout << endl;
    traversal(head);
}

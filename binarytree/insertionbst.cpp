#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;
};

node *createnode(int data)
{
    node *n = (node *)malloc(sizeof(node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void insert(node *root, int key)
{
    node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (root->data == key)
        {
            cout << "cannot insert " << endl;
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    node *new1 = createnode(key);
    if (key < prev->data)
    {
        prev->left = new1;
    }
    else
    {
        prev->right = new1;
    }
}
int main()
{

    node *p = createnode(5);
    node *p1 = createnode(3);
    node *p2 = createnode(6);
    node *p3 = createnode(1);
    node *p4 = createnode(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    insert(p, 16);
    printf("%d", p->right->right->data);
    return 0;
}
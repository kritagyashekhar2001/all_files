#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
};
node *createNode(int data)
{
    node *n;
    n = (node *)malloc(sizeof(node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
node *search(node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}
int main()
{

    node *p = createNode(5);
    node *p1 = createNode(3);
    node *p2 = createNode(2);
    node *p3 = createNode(1);
    node *p4 = createNode(4);
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    node *n = search(p, 1);
    if (n != NULL)
    {
        printf("Found: %d", n->data);
    }
    else
    {
        printf("Element not found");
    }

    return 0;
}

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
node *inorderpredecessor(node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

node *deletekey(node *root, int key)
{
    node *ipre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    if (key < root->data)
    {
        root->left = deletekey(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deletekey(root->right, key);
    }
    else
    {
        ipre = inorderpredecessor(root);
        root->data = ipre->data;
        root->left = deletekey(root->left, key);
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

    inOrder(p);
    printf("\n");
    deletekey(p, 5);
    inOrder(p);

    return 0;
}
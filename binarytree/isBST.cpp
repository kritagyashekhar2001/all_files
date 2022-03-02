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
int isBST(node *root)
{
    static node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}
void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
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
    inOrder(p);
    printf("\n");

    if (isBST(p))
    {
        printf("This is a bst");
    }
    else
    {
        printf("This is not a bst");
    }
    return 0;
}
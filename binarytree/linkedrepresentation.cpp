#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
};

node *link(int data)
{
    node *n = (node *)malloc(sizeof(node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void pretraversal(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        pretraversal(root->left);
        pretraversal(root->right);
    }
}
void posttraversal(node *root)
{
    if (root != NULL)
    {
        posttraversal(root->left);
        posttraversal(root->right);
        cout << root->data << " ";
    }
}
void intraversal(node *root)
{
    if (root != NULL)
    {
        intraversal(root->left);
        cout << root->data << " ";
        intraversal(root->right);
    }
}
int main()
{
    node *p = link(5);
    node *p1 = link(56);
    node *p2 = link(3);

    p->left = p1;
    p->right = p2;
    pretraversal(p);
    cout << endl;
    posttraversal(p);
    cout << endl;
    intraversal(p);
    return 0;
}
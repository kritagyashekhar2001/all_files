#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    int height;
};

int max(int a, int b);
int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(node *Root)
{
    if (Root == NULL)
    {
        return 0;
    }
    return Root->height;
}

node *createNode(int data)
{
    node *n = new node();
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return (n);
}

node *rightrotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left),
                    height(y->right)) +
                1;
    x->height = max(height(x->left),
                    height(x->right)) +
                1;

    // Return new root
    return x;
}

node *leftrotate(node *x)
{
    node *y = x->right;
    node *T2 = y->left;
    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left),
                    height(x->right)) +
                1;
    y->height = max(height(y->left),
                    height(y->right)) +
                1;

    // Return new root
    return y;
}

int getbalance(node *Root)
{
    if (Root == NULL)
    {
        return 0;
    }
    else
    {
        return height(Root->left) - height(Root->right);
    }
}
node *insert(node *Root, int data)
{
    if (Root == NULL)
    {
        return (createNode(data));
    }
    if (data < Root->data)
    {
        Root->left = insert(Root->left, data);
    }
    else if (data > Root->data)
    {
        Root->right = insert(Root->right, data);
    }
    else
    {
        return Root;
    }
    Root->height = 1 + max(height(Root->left),
                           height(Root->right));

    int balance = getbalance(Root);

    if (balance > 1 && data < Root->left->data)
        return rightrotate(Root);

    // Right Right Case
    if (balance < -1 && data > Root->right->data)
        return leftrotate(Root);

    // Left Right Case
    if (balance > 1 && data > Root->left->data)
    {
        Root->left = leftrotate(Root->left);
        return rightrotate(Root);
    }

    // Right Left Case
    if (balance < -1 && data < Root->right->data)
    {
        Root->right = rightrotate(Root->right);
        return leftrotate(Root);
    }
    return Root;
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
    node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    intraversal(root);

    return 0;
}
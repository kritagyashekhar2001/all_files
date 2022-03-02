#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node *cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }
    /*The tree node has data, left child and right child
    class Node {
        int data;
        Node* left;
        Node* right;
    };

    */
    // int height(Node *root)
    // {
    //     // Write your code here.
    //     int max1 = 0, max2 = 0;
    //     if (root->left == NULL && root->right == NULL)
    //     {
    //         return 1;
    //     }
    //     while (root->left != NULL || root->right != NULL)
    //     {
    //         if (root->left != NULL)
    //         {
    //             max1 = max1 + 1;
    //         }
    //         if (root->right != NULL)
    //         {
    //             max2 = max2 + 1;
    //         }
    //     }
    //     if (max1 > max2)
    //     {
    //         return max1;
    //     }
    //     else if (max1 < max2)
    //     {
    //         return max2;
    //     }
    //     else
    //     {
    //         return max1;
    //     }
    // }
    int height(Node *root)
    {
        // Write your code here.
        int leftHeight = 0;
        int rightHeight = 0;

        if (root->left != NULL)
        {
            leftHeight = 1 + height(root->left);
        }

        if (root->right != NULL)
        {
            rightHeight = 1 + height(root->right);
        }

        return leftHeight > rightHeight ? leftHeight : rightHeight;
    }

}; // End of Solution

int main()
{

    Solution myTree;
    Node *root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0)
    {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    int height = myTree.height(root);
    std::cout << height;

    return 0;
}

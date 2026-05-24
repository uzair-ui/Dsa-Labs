#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// BST insertion    (all of following function is explained in task 2 )
Node* insert(Node* root, int value)
{
    if (root == NULL)
    {
        return new Node(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }

    return root;
}

// making Recursive function search 
bool search(Node* root, int value)
{
    if (root == NULL)   // this indicates that there are none value in the tree 
    {
        return false;
    }

    // if root is the value then no need to move further 
    if (root->data == value)
    {
        return true;
    }
    // if root is not the value the check the lefty side of the tree if value is less then root

    // search in left subtree
    if (value < root->data)
    {
        return search(root->left, value);
    }

    // if  value is not found in left subtree then check the right  side of the tree 
    // search in right subtree
    else
    {
        return search(root->right, value);
    }
}

int main()
{
    Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    int value;

    cout << "Enter value to search: ";
    cin >> value;

    if (search(root, value))
    {
        cout << "Value Found";
    }
    else
    {
        cout << "Value Not Found";
    }

    return 0;
}
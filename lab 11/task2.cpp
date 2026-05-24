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

// BST insertion function
Node* insert(Node* root, int value)
{
    if (root == NULL)              // check if root is null then the root becomes new node's value
    {
        return new Node(value);
    }

    // insert in left side
    if (value < root->data)    // if the entered value is less then what is value in the root then push to the left side of tree 
    {
        root->left = insert(root->left, value);
    }

    // if the value is greater then what is value in the root then push to the right side of tree 
    else
    {
        root->right = insert(root->right, value);
    }

    return root;
}

//  display function basic In-order traversal
void inorder(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node* root = NULL;

    // inserting values
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "BST in ascending order: ";
    inorder(root);

    return 0;
}
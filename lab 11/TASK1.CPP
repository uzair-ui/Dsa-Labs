#include <iostream>
using namespace std;



//           structure for creating tree (root , left side , right side pointers)
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

// In-order Traversal
void inorder(Node* root)
{
    if (root == NULL)
    {
        return;
    }


    // uisng recursive functions we'll traverse

    inorder(root->left);   // go to left side of the tree
    cout << root->data << " ";
    inorder(root->right);  // go to right side of the tree
}

// Pre-order Traversal
void preorder(Node* root)
{
    if (root == NULL)
    {
        return;
    }


    // uisng recursive functions we'll traverse

    cout << root->data << " ";
    preorder(root->left);   // go to left side of the tree
    preorder(root->right);  // go to right side of the tree
}

// Post-order Traversal
void postorder(Node* root)
{
    if (root == NULL)
    {
        return;
    }


    // uisng recursive functions we'll traverse

    postorder(root->left);   // go to left side of the tree
    postorder(root->right);  // go to right side of the tree
    cout << root->data << " ";
}

int main()
{
    // creating  sample binary tree for traversal 

    Node* root = new Node(10);

    root->left = new Node(20);
    root->right = new Node(30);

    root->left->left = new Node(40);
    root->left->right = new Node(50);

    cout << "In-order Traversal: ";
    inorder(root);

    cout << "\nPre-order Traversal: ";
    preorder(root);

    cout << "\nPost-order Traversal: ";
    postorder(root);

    return 0;
}
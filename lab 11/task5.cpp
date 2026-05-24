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

// BST insertion already explained
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

// In-order traversal
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

// Find minimum value node
Node* findMin(Node* root)
{
    if (root->left == NULL)
    {
        return root;
    }

    return findMin(root->left);
}

// Recursive delete function
Node* deleteNode(Node* root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }

    // move to left subtree
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }

    // move to right subtree
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }

    // node found
    else
    {
        // no child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // one child
        else if (root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        else if (root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // if have  two children
        else
        {
            // get minimum from right subtree
            Node* temp = findMin(root->right);

            // replace value
            root->data = temp->data;

            // delete duplicate node
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
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

    cout << "BST before deletion: ";
    inorder(root);

    int value;

    cout << "\nEnter value to delete: ";
    cin >> value;

    root = deleteNode(root, value);

    cout << "BST after deletion: ";
    inorder(root);

    return 0;
}
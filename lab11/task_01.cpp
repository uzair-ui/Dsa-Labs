//#include <iostream>
//using namespace std;
//
//// CLASS FOR BST NODE
//
//class Node {
//public:
//    int data;       // stores value of node
//    Node* left;     // pointer to left child
//    Node* right;    // pointer to right child
//
//    // constructor to initialize node
//    Node(int value) {
//        data = value;
//        left = NULL;
//        right = NULL;
//    }
//};
//
//
//// CLASS FOR BINARY SEARCH TREE
//
//class BST {
//private:
//    Node* root; // root of tree
//
//    
//    // INSERT FUNCTION (RECURSIVE)
//    
//    Node* insertNode(Node* temp, int value) {
//
//        // if tree is empty 
//        if (temp == NULL) {
//            temp = new Node(value);
//            return temp;
//        }
//
//        // if value is smaller  go left
//        if (value < temp->data) {
//            temp->left = insertNode(temp->left, value);
//        }
//
//        // if value is greater  go right
//        else if (value > temp->data) {
//            temp->right = insertNode(temp->right, value);
//        }
//
//        // if equal  do nothing (NO duplicates allowed)
//
//        return temp;
//    }
//
//    // INORDER TRAVERSAL
//    // Left -> Root -> Right
//    
//    void inorderTraversal(Node* temp) {
//        if (temp != NULL) {
//            inorderTraversal(temp->left);   // visit left subtree
//            cout << temp->data << " ";      // print root
//            inorderTraversal(temp->right);  // visit right subtree
//        }
//    }
//
//   
//    // PREORDER TRAVERSAL
//    // Root -> Left -> Right
//    
//    void preorderTraversal(Node* temp) {
//        if (temp != NULL) {
//            cout << temp->data << " ";      // print root first
//            preorderTraversal(temp->left);  // then left
//            preorderTraversal(temp->right); // then right
//        }
//    }
//
//    
//    // POSTORDER TRAVERSAL
//    // Left -> Right -> Root
//    
//    void postorderTraversal(Node* temp) {
//        if (temp != NULL) {
//            postorderTraversal(temp->left);   // left
//            postorderTraversal(temp->right);  // right
//            cout << temp->data << " ";       // root last
//        }
//    }
//
// 
//    // SEARCH FUNCTION (RECURSIVE)
//    
//    bool searchNode(Node* temp, int key) {
//
//        // if reached NULL -> not found
//        if (temp == NULL) {
//            return false;
//        }
//
//        // if value matches
//        if (temp->data == key) {
//            return true;
//        }
//
//        // if key is smaller -> search left side
//        else if (key < temp->data) {
//            return searchNode(temp->left, key);
//        }
//
//        // if key is greater -> search right side
//        else {
//            return searchNode(temp->right, key);
//        }
//    }
//
//public:
//    // constructor
//    BST() {
//        root = NULL;
//    }
//
//    // public insert function
//    void insert(int value) {
//        root = insertNode(root, value);
//    }
//
//    // public inorder display
//    void inorder() {
//        cout << "\nInorder Traversal (Sorted Order): ";
//        inorderTraversal(root);
//    }
//
//    // public preorder display
//    void preorder() {
//        cout << "\nPreorder Traversal (Root-Left-Right): ";
//        preorderTraversal(root);
//    }
//
//    // public postorder display
//    void postorder() {
//        cout << "\nPostorder Traversal (Left-Right-Root): ";
//        postorderTraversal(root);
//    }
//
//    // public search function
//    void search(int key) {
//        if (searchNode(root, key)) {
//            cout << "\nKey found in BST";
//        }
//        else {
//            cout << "\nKey not found in BST";
//        }
//    }
//};
//
//
//// MAIN FUNCTION
//
//int main() {
//
//    BST tree;  // creating object
//
//    int n, value;
//
//    // input number of elements
//    cout << "Enter number of values: ";
//    cin >> n;
//
//    // inserting values into BST
//    cout << "Enter values: ";
//    for (int i = 0; i < n; i++) {
//        cin >> value;
//        tree.insert(value);  // insert into BST
//    }
//
//    // display traversals
//    tree.inorder();
//    tree.preorder();
//    tree.postorder();
//
//    // search operation
//    cout << "\nEnter value to search: ";
//    cin >> value;
//
//    tree.search(value);
//
//    return 0;
//}
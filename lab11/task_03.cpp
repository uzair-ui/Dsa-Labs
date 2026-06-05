//#include <iostream>
//using namespace std;
//
//// CLASS FOR BST NODE
//class Node {
//public:
//    int data;       // stores value
//    Node* left;     // left child
//    Node* right;    // right child
//
//    // constructor
//    Node(int value) {
//        data = value;
//        left = NULL;
//        right = NULL;
//    }
//};
//
//// CLASS FOR BST
//class BST {
//private:
//    Node* root;
//
//    // INSERT FUNCTION (RECURSIVE)
//    Node* insertNode(Node* temp, int value) {
//
//        if (temp == NULL) {
//            return new Node(value);
//        }
//
//        if (value < temp->data) {
//            temp->left = insertNode(temp->left, value);
//        }
//        else if (value > temp->data) {
//            temp->right = insertNode(temp->right, value);
//        }
//
//        return temp;
//    }
//
//    // INORDER TRAVERSAL
//    void inorderTraversal(Node* temp) {
//        if (temp != NULL) {
//            inorderTraversal(temp->left);
//            cout << temp->data << " ";
//            inorderTraversal(temp->right);
//        }
//    }
//
//
//    // IDENTICAL TREE CHECK FUNCTION
//    
//    bool isIdentical(Node* root1, Node* root2) {
//
//        // if both are NULL -> identical
//        if (root1 == NULL && root2 == NULL) {
//            return true;
//        }
//
//        // if one is NULL and other is not -> not identical
//        if (root1 == NULL || root2 == NULL) {
//            return false;
//        }
//
//        // if data is different -> not identical
//        if (root1->data != root2->data) {
//            return false;
//        }
//
//        // check left and right subtrees recursively
//        return isIdentical(root1->left, root2->left) &&
//            isIdentical(root1->right, root2->right);
//    }
//
//    // helper wrapper for external call
//    bool checkIdentical(Node* r1, Node* r2) {
//        return isIdentical(r1, r2);
//    }
//
//public:
//    BST() {
//        root = NULL;
//    }
//
//    // insert function
//    void insert(int value) {
//        root = insertNode(root, value);
//    }
//
//    // inorder display
//    void inorder() {
//        inorderTraversal(root);
//    }
//
//    // getter for root (needed for comparison)
//    Node* getRoot() {
//        return root;
//    }
//
//    // public identical check
//    bool compareTrees(Node* r1, Node* r2) {
//        return isIdentical(r1, r2);
//    }
//};
//
//
//// MAIN FUNCTION
//
//int main() {
//
//    BST tree1, tree2;
//
//    int n, value;
//
//    // INPUT FOR FIRST BST
//    cout << "Enter number of nodes for BST 1: ";
//    cin >> n;
//
//    cout << "Enter values for BST 1: ";
//    for (int i = 0; i < n; i++) {
//        cin >> value;
//        tree1.insert(value);
//    }
//
//    // INPUT FOR SECOND BST
//    cout << "\nEnter number of nodes for BST 2: ";
//    cin >> n;
//
//    cout << "Enter values for BST 2: ";
//    for (int i = 0; i < n; i++) {
//        cin >> value;
//        tree2.insert(value);
//    }
//
//    // DISPLAY BOTH TREES
//    cout << "\nBST 1 Inorder: ";
//    tree1.inorder();
//
//    cout << "\nBST 2 Inorder: ";
//    tree2.inorder();
//
//    // CHECK IDENTICAL
//    if (tree1.compareTrees(tree1.getRoot(), tree2.getRoot())) {
//        cout << "\nBSTs are IDENTICAL";
//    }
//    else {
//        cout << "\nBSTs are NOT IDENTICAL";
//    }
//
//    return 0;
//}
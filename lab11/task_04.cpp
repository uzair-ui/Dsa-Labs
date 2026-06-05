#include <iostream>
using namespace std;


// CLASS FOR BST NODE

class Node {
public:
    int isbn;          // book ISBN (key)
    string title;      // book title
    Node* left;        // left child
    Node* right;       // right child

    Node(int i, string t) {
        isbn = i;
        title = t;
        left = NULL;
        right = NULL;
    }
};


// CLASS FOR LINKED LIST NODE

class ListNode {
public:
    int isbn;
    string title;
    ListNode* next;

    ListNode(int i, string t) {
        isbn = i;
        title = t;
        next = NULL;
    }
};

// BST CLASS

class BST {
private:
    Node* root;

    // INSERT INTO BST
    Node* insertNode(Node* temp, int isbn, string title) {

        if (temp == NULL) {
            return new Node(isbn, title);
        }

        if (isbn < temp->isbn) {
            temp->left = insertNode(temp->left, isbn, title);
        }
        else if (isbn > temp->isbn) {
            temp->right = insertNode(temp->right, isbn, title);
        }

        // no duplicates allowed
        return temp;
    }

    // INORDER TRAVERSAL used for conversion
    void inorderTraversal(Node* temp) {
        if (temp != NULL) {
            inorderTraversal(temp->left);
            cout << temp->isbn << " - " << temp->title << endl;
            inorderTraversal(temp->right);
        }
    }

    
    // CONVERT BST → LINKED LIST
   
    void bstToList(Node* temp, ListNode*& head, ListNode*& tail) {

        if (temp == NULL) {
            return;
        }

        // LEFT SUBTREE
        bstToList(temp->left, head, tail);

        // CREATE LIST NODE
        ListNode* newNode = new ListNode(temp->isbn, temp->title);

        // FIRST NODE
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }

        // RIGHT SUBTREE
        bstToList(temp->right, head, tail);
    }

public:
    BST() {
        root = NULL;
    }

    // INSERT FUNCTION
    void insert(int isbn, string title) {
        root = insertNode(root, isbn, title);
    }

    // PRINT BST INORDER
    void showBST() {
        cout << "\nBST (Inorder - Sorted):\n";
        inorderTraversal(root);
    }

    // CONVERT FUNCTION
    ListNode* convertToList() {

        ListNode* head = NULL;
        ListNode* tail = NULL;

        bstToList(root, head, tail);

        return head;
    }

    // GET ROOT (not needed but kept for safety)
    Node* getRoot() {
        return root;
    }
};


// PRINT LINKED LIST

void printList(ListNode* head) {

    cout << "\nSorted Linked List (Library Catalog):\n";

    while (head != NULL) {
        cout << head->isbn << " - " << head->title << endl;
        head = head->next;
    }
}


// MAIN FUNCTION

int main() {

    BST tree;

    int n, isbn;
    string title;

    cout << "Enter number of books: ";
    cin >> n;

    cout << "Enter ISBN and Title:\n";

    for (int i = 0; i < n; i++) {
        cin >> isbn;
        cin >> title; // single word title (no spaces)
        tree.insert(isbn, title);
    }

    // SHOW BST
    tree.showBST();

    // CONVERT TO LINKED LIST
    ListNode* head = tree.convertToList();

    // PRINT LINKED LIST
    printList(head);

    return 0;
}
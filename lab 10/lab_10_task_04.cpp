#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void printList(Node* head)
{
    if (head == NULL)
        return;

    cout << head->data << " ";
    printList(head->next);
}

int main()
{
    Node* head = new Node;
    head->data = 10;
    head->next = new Node;

    head->next->data = 20;
    head->next->next = new Node;

    head->next->next->data = 30;
    head->next->next->next = NULL;

    cout << "Linked List Elements: ";
    printList(head);

    return 0;
}
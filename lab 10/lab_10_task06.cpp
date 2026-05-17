#include <iostream>
using namespace std;

struct DNode
{
    int data;
    DNode* next;
    DNode* prev;

    DNode(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

void printForward(DNode* head)
{
    if (head == NULL)
    {
        cout << endl;
        return;
    }

    cout << head->data << " ";
    printForward(head->next);
}

void printReverse(DNode* tail)
{
    if (tail == NULL)
    {
        cout << endl;
        return;
    }

    cout << tail->data << " ";
    printReverse(tail->prev);
}

DNode* getTail(DNode* head)
{
    if (head == NULL || head->next == NULL)
        return head;

    return getTail(head->next);
}

DNode* insertBeginning(DNode* head, int value)
{
    DNode* newNode = new DNode(value);
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    return newNode;
}

DNode* insertEnd(DNode* head, int value)
{
    if (head == NULL)
        return new DNode(value);

    if (head->next == NULL)
    {
        DNode* newNode = new DNode(value);
        head->next = newNode;
        newNode->prev = head;
        return head;
    }

    insertEnd(head->next, value);
    return head;
}

DNode* insertPosition(DNode* head, int value, int pos)
{
    if (pos <= 1 || head == NULL)
    {
        DNode* newNode = new DNode(value);
        newNode->next = head;

        if (head != NULL)
            head->prev = newNode;

        return newNode;
    }

    head->next = insertPosition(head->next, value, pos - 1);

    if (head->next != NULL)
        head->next->prev = head;

    return head;
}

DNode* deleteByValue(DNode* head, int value)
{
    if (head == NULL)
        return NULL;

    if (head->data == value)
    {
        DNode* temp = head->next;

        if (temp != NULL)
            temp->prev = NULL;

        delete head;
        return temp;
    }

    head->next = deleteByValue(head->next, value);

    if (head->next != NULL)
        head->next->prev = head;

    return head;
}

DNode* deletePosition(DNode* head, int pos)
{
    if (head == NULL)
        return NULL;

    if (pos == 1)
    {
        DNode* temp = head->next;

        if (temp != NULL)
            temp->prev = NULL;

        delete head;
        return temp;
    }

    head->next = deletePosition(head->next, pos - 1);

    if (head->next != NULL)
        head->next->prev = head;

    return head;
}

int search(DNode* head, int value, int pos = 1)
{
    if (head == NULL)
        return -1;

    if (head->data == value)
        return pos;

    return search(head->next, value, pos + 1);
}

bool palindromeCheck(DNode*& left, DNode* right)
{
    if (right == NULL)
        return true;

    bool check = palindromeCheck(left, right->next);

    if (!check)
        return false;

    bool same = (left->data == right->data);
    left = left->next;

    return same;
}

bool isPalindrome(DNode* head)
{
    return palindromeCheck(head, head);
}

int main()
{
    DNode* head = NULL;

    head = insertBeginning(head, 1);
    printForward(head);

    head = insertEnd(head, 2);
    printForward(head);

    head = insertEnd(head, 1);
    printForward(head);

    head = insertPosition(head, 5, 2);
    printForward(head);

    head = deleteByValue(head, 5);
    printForward(head);

    head = deletePosition(head, 2);
    printForward(head);

    cout << search(head, 1) << endl;

    DNode* tail = getTail(head);
    printReverse(tail);

    if (isPalindrome(head))
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    return 0;
}
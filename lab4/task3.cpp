#include <iostream>
using namespace std;

class Queue {
public:
    int arr[100];
    int front = 0, rear = -1, size = 0;

    void enqueue(int x) {
        if (size < 100) {
            rear = (rear + 1) % 100;
            arr[rear] = x;
            size++;
        }
    }

    int dequeue() {
        if (size > 0) {
            int x = arr[front];
            front = (front + 1) % 100;
            size--;
            return x;
        }
        return -1;
    }

    int getSize() {
        return size;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % 100] << " ";
        }
        cout << endl;
    }
};

class Stack {
public:
    int arr[100];
    int top = -1;

    void push(int x) {
        arr[++top] = x;
    }

    int pop() {
        return arr[top--];
    }
};

int main() {
    Queue q;
    int n, k, x;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.enqueue(x);
    }

    cin >> k;

    if (k > q.getSize()) k = q.getSize();
    if (k <= 1) {
        q.display();
        return 0;
    }

    Stack s;

    for (int i = 0; i < k; i++) {
        s.push(q.dequeue());
    }

    while (s.top != -1) {
        q.enqueue(s.pop());
    }

    int rem = q.getSize() - k;

    for (int i = 0; i < rem; i++) {
        q.enqueue(q.dequeue());
    }

    q.display();
}
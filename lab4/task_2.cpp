#include <iostream>
using namespace std;

class Stack {
public:
    int arr[100];
    int top = -1;

    void push(int x) {
        if (top < 99) {
            arr[++top] = x;
        }
    }

    int pop() {
        if (top >= 0) {
            return arr[top--];
        }
        return -1;
    }

    int peek() {
        if (top >= 0) {
            return arr[top];
        }
        return -1;
    }

    bool isEmpty() {
        return top == -1;
    }
};

class Queue {
    Stack s1, s2;

public:
    void enqueue(int x) {
        s1.push(x);
    }

    int dequeue() {
        if (s2.isEmpty()) {
            while (!s1.isEmpty()) {
                s2.push(s1.pop());
            }
        }
        return s2.pop();
    }

    int front() {
        if (s2.isEmpty()) {
            while (!s1.isEmpty()) {
                s2.push(s1.pop());
            }
        }
        return s2.peek();
    }

    void display() {
        Stack t1 = s1;
        Stack t2 = s2;

        while (!t2.isEmpty()) {
            cout << t2.pop() << " ";
        }

        int temp[100];
        int i = 0;

        while (!t1.isEmpty()) {
            temp[i++] = t1.pop();
        }

        for (int j = i - 1; j >= 0; j--) {
            cout << temp[j] << " ";
        }

        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();
    cout << q.dequeue() << endl;
    cout << q.front() << endl;
}
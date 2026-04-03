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

    int peek() {
        return arr[front];
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % 100] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, id;

    while (true) {
        cout << "1 Add\n2 Resolve\n3 Front\n4 Display\n5 Exit\n";
        cin >> choice;

        if (choice == 1) {
            cin >> id;
            q.enqueue(id);
        }
        else if (choice == 2) {
            cout << q.dequeue() << endl;
        }
        else if (choice == 3) {
            cout << q.peek() << endl;
        }
        else if (choice == 4) {
            q.display();
        }
        else {
            break;
        }
    }
}
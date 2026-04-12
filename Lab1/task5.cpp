#include <iostream>
using namespace std;

class Queue {
public:
    string arr[100];
    int front = 0, rear = -1, size = 0;

    void enqueue(string x) {
        if (size < 100) {
            rear = (rear + 1) % 100;
            arr[rear] = x;
            size++;
        }
    }

    string dequeue() {
        if (size > 0) {
            string x = arr[front];
            front = (front + 1) % 100;
            size--;
            return x;
        }
        return "";
    }

    string peek() {
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
    int choice;
    string doc;

    while (true) {
        cout << "1 Add\n2 Print\n3 Front\n4 Display\n5 Exit\n";
        cin >> choice;

        if (choice == 1) {
            cin >> doc;
            q.enqueue(doc);
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
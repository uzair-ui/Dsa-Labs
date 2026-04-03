#include <iostream>
using namespace std;

struct Package {
    int id;
    string address;
    int start;
    int end;
};

class Queue {
public:
    Package arr[100];
    int front = 0, rear = -1, size = 0;

    void enqueue(Package p) {
        if (size < 100) {
            rear = (rear + 1) % 100;
            arr[rear] = p;
            size++;
        }
    }

    Package dequeue() {
        Package p;
        if (size > 0) {
            p = arr[front];
            front = (front + 1) % 100;
            size--;
        }
        return p;
    }

    Package peek() {
        return arr[front];
    }

    void display() {
        for (int i = 0; i < size; i++) {
            Package p = arr[(front + i) % 100];
            cout << p.id << " " << p.address << " " << p.start << "-" << p.end << endl;
        }
    }

    bool canDeliver(int time) {
        if (size == 0) return false;
        Package p = peek();
        return time >= p.start && time <= p.end;
    }
};

int main() {
    Queue q;
    int choice;

    while (true) {
        cout << "1 Add\n2 Deliver\n3 Front\n4 Display\n5 Exit\n";
        cin >> choice;

        if (choice == 1) {
            Package p;
            cin >> p.id >> p.address >> p.start >> p.end;
            q.enqueue(p);
        }
        else if (choice == 2) {
            int time;
            cin >> time;

            if (q.canDeliver(time)) {
                Package p = q.dequeue();
                cout << p.id << endl;
            }
            else {
                q.dequeue();
                cout << "Expired\n";
            }
        }
        else if (choice == 3) {
            Package p = q.peek();
            cout << p.id << endl;
        }
        else if (choice == 4) {
            q.display();
        }
        else {
            break;
        }
    }
}
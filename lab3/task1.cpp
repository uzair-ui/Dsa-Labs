//#include <iostream>
//using namespace std;
//
//
//template <typename T>
//class AbstractStack {
//public:
//    virtual void push(T value) = 0;
//    virtual T pop() = 0;
//    virtual T top() const = 0;
//    virtual bool isEmpty() const = 0;
//    virtual bool isFull() const = 0;
//    virtual ~AbstractStack() {}
//};
//
//
//template <typename T>
//class myStack : public AbstractStack<T> {
//private:
//    T* arr;
//    int topIndex;
//    int maxSize;
//
//public:
//    
//    myStack(int size) {
//        maxSize = size;
//        arr = new T[maxSize];
//        topIndex = -1;
//    }
//
//    
//    ~myStack() {
//        delete[] arr;
//    }
//
//    
//    void push(T value) {
//        if (isFull()) {
//            cout << "Stack Overflow\n";
//            return;
//        }
//        arr[++topIndex] = value;
//    }
//
//    
//    T pop() {
//        if (isEmpty()) {
//            cout << "Stack Underflow\n";
//            return T();
//        }
//        return arr[topIndex--];
//    }
//
//    
//    T top() const {
//        if (isEmpty()) {
//            cout << "Stack is Empty\n";
//            return T();
//        }
//        return arr[topIndex];
//    }
//
//    
//    bool isEmpty() const {
//        return topIndex == -1;
//    }
//
//    
//    bool isFull() const {
//        return topIndex == maxSize - 1;
//    }
//
//    
//    void display() const {
//        if (isEmpty()) {
//            cout << "Stack is Empty"<<endl;
//            return;
//        }
//
//        cout << "Stack elements (Top to Bottom): " << endl;;
//        for (int i = topIndex; i >= 0; i--) {
//            cout << arr[i] << endl;
//        }
//    }
//};
//
//int main() {
//    int size;
//    cout << "Enter stack size: ";
//    cin >> size;
//
//    myStack<int> s(size);
//
//    int choice, value;
//
//    do {
//        cout << "\n--- Stack Menu ---\n";
//        cout << "1. Push\n";
//        cout << "2. Pop\n";
//        cout << "3. Top\n";
//        cout << "4. isEmpty\n";
//        cout << "5. isFull\n";
//        cout << "6. Display\n";
//        cout << "0. Exit\n";
//        cout << "Enter choice: ";
//        cin >> choice;
//
//        if (choice == 1) {
//            cout << "Enter value: ";
//            cin >> value;
//            s.push(value);
//        }
//        else if (choice == 2) {
//            cout << "Popped: " << s.pop() << endl;
//        }
//        else if (choice == 3) {
//            cout << "Top: " << s.top() << endl;
//        }
//        else if (choice == 4) {
//            if (s.isEmpty()) {
//                cout << "Stack is Empty\n";
//            }
//            else {
//                cout << "Stack is Not Empty\n";
//            }
//        }
//        else if (choice == 5) {
//            if (s.isFull()) {
//                cout << "Stack is Full\n";
//            }
//            else {
//                cout << "Stack is Not Full\n";
//            }
//        }
//        else if (choice == 6) {
//            s.display();
//        }
//        else if (choice == 0) {
//            cout << "Exiting...\n";
//        }
//        else {
//            cout << "Invalid choice\n";
//        }
//
//    } while (choice != 0);
//
//    return 0;
//}
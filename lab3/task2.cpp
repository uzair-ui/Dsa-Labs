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
//    T* minArr;     
//    int topIndex;
//    int minTop;
//    int maxSize;
//
//public:
//    
//    myStack(int size) {
//        maxSize = size;
//        arr = new T[maxSize];
//        minArr = new T[maxSize];
//        topIndex = -1;
//        minTop = -1;
//    }
//
//    
//    ~myStack() {
//        delete[] arr;
//        delete[] minArr;
//    }
//
//    
//    void push(T value) {
//        if (isFull()) {
//            cout << "Stack Overflow"<<endl;
//            return;
//        }
//
//        
//        topIndex++;
//        arr[topIndex] = value;
//
//       
//        if (minTop == -1 || value <= minArr[minTop]) {
//            minTop++;
//            minArr[minTop] = value;
//        }
//    }
//
//   
//    T pop() {
//        if (isEmpty()) {
//            cout << "Stack Underflow" << endl;
//            return T();
//        }
//
//        T removed = arr[topIndex];
//
//        
//        if (removed == minArr[minTop]) {
//            minTop--;
//        }
//
//        topIndex--;
//        return removed;
//    }
//
//   
//    T top() const {
//        if (isEmpty()) {
//            cout << "Stack is Empty" << endl;
//            return T();
//        }
//        return arr[topIndex];
//    }
//
//    T getMin() const {
//        if (isEmpty()) {
//            cout << "Stack is Empty" << endl;
//            return T();
//        }
//        return minArr[minTop];
//    }
//
//   
//    bool isEmpty() const {
//        if (topIndex == -1)
//            return true;
//        else
//            return false;
//    }
//
//   
//    bool isFull() const {
//        if (topIndex == maxSize - 1)
//            return true;
//        else
//            return false;
//    }
//
//   
//    void display() const {
//        if (isEmpty()) {
//            cout << "Stack is Empty" << endl;
//            return;
//        }
//
//        cout << "Stack elements (Top to Bottom): " << endl;
//        for (int i = topIndex; i >= 0; i--) {
//            cout << arr[i] << endl;
//        }
//    }
//};
//
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
//        cout << "1. Push element\n";
//        cout << "2. Pop element\n";
//        cout << "3. Show top element\n";
//        cout << "4. Check if stack is empty\n";
//        cout << "5. Check if stack is full\n";
//        cout << "6. Display stack elements\n";
//        cout << "7. Show minimum element\n";
//        cout << "8. Exit\n";
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
//            cout << "Top element: " << s.top() << endl;
//        }
//        else if (choice == 4) {
//            if (s.isEmpty())
//                cout << "Stack is Empty\n";
//            else
//                cout << "Stack is Not Empty\n";
//        }
//        else if (choice == 5) {
//            if (s.isFull())
//                cout << "Stack is Full\n";
//            else
//                cout << "Stack is Not Full\n";
//        }
//        else if (choice == 6) {
//            s.display();
//        }
//        else if (choice == 7) {
//            cout << "Minimum element: " << s.getMin() << endl;
//        }
//        else if (choice == 8) {
//            cout << "Exiting..." << endl;
//        }
//        else {
//            cout << "Invalid choice" << endl;
//        }
//
//    } while (choice != 8);
//
//    return 0;
//}
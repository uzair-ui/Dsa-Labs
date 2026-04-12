#include <iostream>
#include <string>
using namespace std;

class myCarStack {
private:
    string* arr;
    int topIndex;
    int maxSize;

public:
    
    myCarStack(int size) {
        maxSize = size;
        arr = new string[maxSize];
        topIndex = -1;
    }

    
    ~myCarStack() {
        delete[] arr;
    }

    
    bool isEmpty() {
        if (topIndex == -1)
            return true;
        else
            return false;
    }

    
    bool isFull() {
        if (topIndex == maxSize - 1)
            return true;
        else
            return false;
    }

    
    void push(string car) {
        if (isFull()) {
            cout << "Parking is FULL\n";
            return;
        }
        topIndex++;
        arr[topIndex] = car;
        cout << "Car parked: " << car << endl;
    }

   
    string pop() {
        if (isEmpty()) {
            return "";
        }
        string car = arr[topIndex];
        topIndex--;
        return car;
    }


    void display() {
        if (isEmpty()) {
            cout << "No cars parked\n";
            return;
        }

        cout << "Cars in Parking (Top to Bottom):\n";
        for (int i = topIndex; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }

    int count() {
        return topIndex + 1;
    }

    
    bool search(string car) {
        for (int i = 0; i <= topIndex; i++) {
            if (arr[i] == car)
                return true;
        }
        return false;
    }

    
    void removeCar(string car) {
        if (isEmpty()) {
            cout << "Parking is empty\n";
            return;
        }

        myCarStack temp(maxSize); 
        bool found = false;

        while (!isEmpty()) {
            string topCar = pop();

            if (topCar == car) {
                cout << "Car removed: " << car << endl;
                found = true;
                break;
            }
            else {
                temp.push(topCar);
            }
        }

        
        while (!temp.isEmpty()) {
            push(temp.pop());
        }

        if (!found) {
            cout << "Car not found\n";
        }
    }
};
int main() {
    myCarStack parking(8); 

    int choice;
    string carNumber;

    do {
        cout << "\n--- Parking Lot Menu ---\n";
        cout << "1. Park a new car\n";
        cout << "2. Remove a car\n";
        cout << "3. View parked cars\n";
        cout << "4. Total cars parked\n";
        cout << "5. Search for a car\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter car number/name: ";
            cin >> carNumber;
            parking.push(carNumber);
        }
        else if (choice == 2) {
            cout << "Enter car number/name to remove: ";
            cin >> carNumber;
            parking.removeCar(carNumber);
        }
        else if (choice == 3) {
            parking.display();
        }
        else if (choice == 4) {
            cout << "Total cars parked: " << parking.count() << endl;
        }
        else if (choice == 5) {
            cout << "Enter car number to search: ";
            cin >> carNumber;

            if (parking.search(carNumber)) {
                cout << "Car is in parking\n";
            }
            else {
                cout << "Car not found\n";
            }
        }
        else if (choice == 6) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice\n";
        }

    } while (choice != 6);

    return 0;
}
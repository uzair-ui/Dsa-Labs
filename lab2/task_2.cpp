#include<iostream>
using namespace std;

class Employee {
public:
    virtual float calculateSalary() = 0; 
};

class FullTimeEmployee : public Employee {
private:
    float fixedSalary;

public:
    void setSalary(float s) {
        fixedSalary = s;
    }

    float calculateSalary() {
        return fixedSalary;
    }
};

class PartTimeEmployee : public Employee {
private:
    int hoursWorked;
    float hourlyRate;

public:
    void setDetails(int h, float r) {
        hoursWorked = h;
        hourlyRate = r;
    }

    float calculateSalary() {
        return hoursWorked * hourlyRate;
    }
};

int main() {

    FullTimeEmployee f1;
    PartTimeEmployee p1;

    f1.setSalary(50000);
    p1.setDetails(40, 500);

    cout << "Full Time Employee Salary: " << f1.calculateSalary() << endl;
    cout << "Part Time Employee Salary: " << p1.calculateSalary() << endl;

    return 0;
}
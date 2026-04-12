//#include<iostream>
//using namespace std;
//
//class Shape {
//public:
//    virtual int area() = 0;   
//};
//
//class Circle : public Shape {
//private:
//    int radius;
//
//public:
//    Circle(int r = 0) {
//        radius = r;
//    }
//
//    int area() {
//        return radius * radius;
//    }
//};
//
//class Rectangle : public Shape {
//private:
//    int length;
//    int width;
//
//public:
//    Rectangle(int l = 0, int w = 0) {
//        length = l;
//        width = w;
//    }
//
//    int area() {
//        return length * width;
//    }
//};
//
//int main() {
//
//    Circle c1(5);
//    Rectangle r1(4, 6);
//
//    cout << "Circle Area: " << c1.area() << endl;
//    cout << "Rectangle Area: " << r1.area() << endl;
//
//    return 0;
//}
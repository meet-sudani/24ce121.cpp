#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Base class
class Shape {
public:
    virtual double Area() const = 0;
    virtual void display() const = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double Area() const override {
        return length * width;
    }

    void display() const override {
        cout << "Rectangle: Length = " << length << ", Width = " << width << endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double Area() const override {
        return M_PI * radius * radius;
    }

    void display() const override {
        cout << "Circle: Radius = " << radius << endl;
    }
};

int main() {
    vector<Shape*> shapes;

    shapes.push_back(new Rectangle(5.0, 3.0));
    shapes.push_back(new Circle(2.0));
    shapes.push_back(new Rectangle(7.0, 4.0));
    shapes.push_back(new Circle(5.5));

    cout << "--- Dynamic Management (vector) ---" << endl;
    for (auto shape : shapes) {
        shape->display();
        cout << "Area = " << shape->Area() << endl;
        cout << "--------------------------" << endl;
    }

    for (auto shape : shapes) {
        delete shape;
    }
    shapes.clear();

    cout << endl;

    const int SIZE = 2;
    Shape* staticShapes[SIZE];

    staticShapes[0] = new Rectangle(2.0, 8.0);
    staticShapes[1] = new Circle(3.5);

    cout << "--- Static Management (array) ---" << endl;
    for (int i = 0; i < SIZE; ++i) {
        staticShapes[i]->display();
        cout << "Area = " << staticShapes[i]->Area() << endl;
        cout << "--------------------------" << endl;
    }

    for (int i = 0; i < SIZE; ++i) {
        delete staticShapes[i];
    }

    return 0;
}


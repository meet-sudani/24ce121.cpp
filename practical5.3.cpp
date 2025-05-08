#include <iostream>
#include <stack>
using namespace std;

class Point {
private:
    double x, y;

public:
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    Point operator-() const {
        return Point(-x, -y);
    }

    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    bool operator==(const Point& other) const {
        return (x == other.x) && (y == other.y);
    }

    void print() const {
        cout << "(" << x << ", " << y << ")";
    }

    double getX() const { return x; }
    double getY() const { return y; }
};

stack<Point> history;

void saveState(const Point& p) {
    history.push(p);
}

Point undo() {
    if (history.empty()) {
        cout << "No operations to undo!\n";
        return Point();
    }
    Point last = history.top();
    history.pop();
    return last;
}

int main() {
    Point p1(2, 3), p2(4, 5), current;

    current = p1;
    saveState(current);

    cout << "Initial Point: ";
    current.print();
    cout << endl;

    current = current + p2;
    saveState(current);

    cout << "After adding (4,5): ";
    current.print();
    cout << endl;

    current = -current;
    saveState(current);

    cout << "After negation: ";
    current.print();
    cout << endl;

    current = undo();
    cout << "After undoing last operation: ";
    current.print();
    cout << endl;

    current = undo();
    cout << "After undoing another operation: ";
    current.print();
    cout << endl;

    cout << "Is current point equal to (2,3)? ";
    cout << (current == Point(2, 3) ? "Yes" : "No") << endl;

    return 0;
}

#include <iostream>
using namespace std;

class Base {
public:

    virtual ~Base() {
        cout << "Base class destructor called" << endl;
    }

    virtual void display() {
        cout << "Base class display" << endl;
    }
};


class Derived : public Base {
private:
    int* data;

public:
    Derived(int val) {
        data = new int(val);
        cout << "Derived class constructor called" << endl;
    }

    ~Derived() override {
        delete data;
        cout << "Derived class destructor called" << endl;
    }

    void display() override {
        cout << "Derived class display: " << *data << endl;
    }
};

int main() {

    Base* obj = new Derived(100);

    obj->display();


    delete obj;

    return 0;
}

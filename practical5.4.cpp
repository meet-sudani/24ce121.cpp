#include <iostream>
#include <queue>
using namespace std;

class Fahrenheit;

class Celsius {
private:
    double tempC;

public:
    Celsius(double t = 0.0) : tempC(t) {}

    operator Fahrenheit();

    bool operator==(const Celsius& other) const {
        return tempC == other.tempC;
    }

    double getTemp() const { return tempC; }

    void print() const {
        cout << tempC << "°C";
    }
};

class Fahrenheit {
private:
    double tempF;

public:
    Fahrenheit(double t = 32.0) : tempF(t) {}

    operator Celsius() {
        return Celsius((tempF - 32) * 5.0 / 9.0);
    }

    bool operator==(const Fahrenheit& other) const {
        return tempF == other.tempF;
    }

    double getTemp() const { return tempF; }

    void print() const {
        cout << tempF << "°F";
    }
};

Celsius::operator Fahrenheit() {
    return Fahrenheit(tempC * 9.0 / 5.0 + 32);
}

int main() {
    Celsius c1(0.0), c2(100.0);
    Fahrenheit f1(32.0), f2(212.0);

    Fahrenheit f_from_c1 = c1;
    Fahrenheit f_from_c2 = c2;

    Celsius c_from_f1 = f1;
    Celsius c_from_f2 = f2;

    cout << "Conversions:\n";
    cout << "0°C -> "; f_from_c1.print(); cout << endl;
    cout << "100°C -> "; f_from_c2.print(); cout << endl;
    cout << "32°F -> "; c_from_f1.print(); cout << endl;
    cout << "212°F -> "; c_from_f2.print(); cout << endl;

    cout << "\nComparisons:\n";
    cout << "Is 0°C equal to 32°F? ";
    cout << (c1 == (Celsius)f1 ? "Yes" : "No") << endl;

    cout << "Is 100°C equal to 212°F? ";
    cout << (c2 == (Celsius)f2 ? "Yes" : "No") << endl;

    queue<Fahrenheit> tempQueue;
    tempQueue.push(f_from_c1);
    tempQueue.push(f_from_c2);
    tempQueue.push(f1);
    tempQueue.push(f2);

    cout << "\nProcessing temperatures from the queue:\n";
    while (!tempQueue.empty()) {
        Fahrenheit temp = tempQueue.front();
        tempQueue.pop();
        temp.print();
        cout << endl;
    }

    return 0;
}


#include <iostream>
#include <vector>
using namespace std;

class Complex
{
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    Complex operator + (const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator - (const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    friend ostream& operator << (ostream& out, const Complex& c);

    friend istream& operator >> (istream& in, Complex& c);
};

ostream& operator << (ostream& out, const Complex& c) {
    out << "(" << c.real << " + " << c.imag << "i)";
    return out;
}

istream& operator >> (istream& in, Complex& c) {
    cout << "Enter real part: ";
    in >> c.real;
    cout << "Enter imaginary part: ";
    in >> c.imag;
    return in;
}

Complex addAll(const vector<Complex>& numbers) {
    Complex sum;
    for (const auto& num : numbers) {
        sum = sum + num;
    }
    return sum;
}

Complex subtractAll(const vector<Complex>& numbers) {
    if (numbers.empty()) return Complex();
    Complex result = numbers[0];
    for (size_t i = 1; i < numbers.size(); ++i) {
        result = result - numbers[i];
    }
    return result;
}

int main() {
    Complex c1, c2;

    cout << "Enter first complex number:\n";
    cin >> c1;
    cout << "Enter second complex number:\n";
    cin >> c2;

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;

    cout << "\nSum: " << sum << endl;
    cout << "Difference: " << diff << endl;

    int n;
    cout << "\nEnter number of complex numbers for batch operations: ";
    cin >> n;
    vector<Complex> numbers(n);
    for (int i = 0; i < n; ++i) {
        cout << "\nEnter complex number " << i+1 << ":\n";
        cin >> numbers[i];
    }

    Complex totalSum = addAll(numbers);
    Complex totalDiff = subtractAll(numbers);

    cout << "\nSum of all complex numbers: " << totalSum << endl;
    cout << "Subtraction of all complex numbers: " << totalDiff << endl;

    return 0;
}

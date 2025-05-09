#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

double readPositiveDouble(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a numeric value.\n";
        } else if (value < 0) {

            cout << "Please enter a positive number.\n";
        } else {
            break;
        }
    }
    return value;
}

int main() {
    cout << "--- Loan to Income Ratio Calculator ---\n";

    double loanAmount = readPositiveDouble("Enter total loan amount: ");
    double income = 0;

    while (true) {
        income = readPositiveDouble("Enter your annual income: ");
        if (income == 0) {
            cout << "Income cannot be zero. Please enter a non-zero income.\n";
        } else {
            break;
        }
    }

    double ratio = loanAmount / income;

    cout << fixed << setprecision(2);
    cout << "\nLoan-to-Income Ratio: " << ratio << endl;

    if (ratio > 3.5)
        cout << "Warning: High loan-to-income ratio.\n";
    else if (ratio > 2.5)
        cout << "Moderate risk.\n";
    else
        cout << "Low risk.\n";

    return 0;
}


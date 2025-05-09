#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

const int MAX_TRANSACTIONS = 100;

class BankAccount {
private:
    string accountHolder;
    double balance;
    string transactions[MAX_TRANSACTIONS];
    int transactionCount;

    void logTransaction(const string& message) {
        if (transactionCount < MAX_TRANSACTIONS) {
            transactions[transactionCount++] = message;
        } else {
            cout << "Transaction log full. Unable to record more transactions.\n";
        }
    }

    void logError(const string& functionName, const string& errorMessage) {
        cout << "[ERROR] in function '" << functionName << "': " << errorMessage << endl;
        logTransaction("ERROR in " + functionName + ": " + errorMessage);
    }

public:
    BankAccount(const string& name, double initialBalance) {
        accountHolder = name;
        balance = initialBalance;
        transactionCount = 0;
        logTransaction("Account created for " + accountHolder + " with initial balance: " + to_string(balance));
    }

    void deposit(double amount) {
        if (amount <= 0) {
            logError("deposit", "Attempt to deposit non-positive amount.");
            return;
        }
        balance += amount;
        logTransaction("Deposited: $" + to_string(amount));
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            logError("withdraw", "Attempt to withdraw non-positive amount.");
            return;
        }
        if (amount > balance) {
            logError("withdraw", "Attempt to withdraw $" + to_string(amount) + " with only $" + to_string(balance) + " available.");
            return;
        }
        balance -= amount;
        logTransaction("Withdrawn: $" + to_string(amount));
    }

    void displayBalance() const {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Current Balance: $" << fixed << setprecision(2) << balance << endl;
    }

    void showTransactionHistory() const {
        cout << "\nTransaction History for " << accountHolder << ":\n";
        for (int i = 0; i < transactionCount; ++i) {
            cout << i + 1 << ". " << transactions[i] << endl;
        }
        if (transactionCount == 0) {
            cout << "No transactions available.\n";
        }
    }
};

int main() {
    BankAccount user("John Doe", 10000.0);

    user.deposit(2500);
    user.withdraw(500);
    user.withdraw(20000);
    user.deposit(-50);
    user.withdraw(1000);

    user.displayBalance();
    user.showTransactionHistory();

    return 0;
}


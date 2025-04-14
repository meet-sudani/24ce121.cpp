#include <iostream>
using namespace std;

class Bank_account
{
    static int minimum_balance;
    int account_number;
    string account_holder_name;
    float balance;

public:
    void add_account()
    {
        float temp_balance;
        cout << "Enter your Account number : ";
        cin >> account_number;
        cout << "Enter Accoutn holder name : ";
        cin >> account_holder_name;
        cout << "Enter balance : ";
        cin >> temp_balance;
        if (temp_balance >= minimum_balance)
        {
            balance = temp_balance;
        }
        else
        {
            cout << "ERROR : Enter amount greater than or equal to " << minimum_balance << endl;
        }
    }
    void deposit()
    {
        float temp_amount;
        cout << "Enter amount to be deposited : ";
        cin >> temp_amount;
        balance = balance + temp_amount;
        cout << "Amount deposited successfuly : " << endl;
    }
    void withdraw()
    {
        float temp_amount;
        cout << "Enter amount to withdrawn : ";
        cin >> temp_amount;
        if (balance - temp_amount >= minimum_balance)
        {
            balance = balance - temp_amount;
            cout << "RS." << temp_amount << " withdrawm successffuly" << endl;
        }
        else
        {
            cout << "ERROR : INSUFFICENT BALANCE " << endl;
        }
    }
    int check(int temp_account_number)
    {
        if (account_number == temp_account_number)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void display_details()
    {
        cout << "Account holder name : " << account_holder_name << endl;
        cout << "Account Number : " << account_number << endl;
        cout << "Account balance : " << balance << endl;
    }
};
int Bank_account ::minimum_balance = 5000;
int main()
{
    int choice, account_count = 0, temp_account_number, i;
    Bank_account a[10];
    do
    {
        cout << "Enter 1 to add account" << endl;
        cout << "Enter 2 to deposit amount" << endl;
        cout << "Enter 3 to withdraw amount" << endl;
        cout << "Enter 4 to display Account details" << endl;
        cout << "Enter 0 to exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            a[account_count].add_account();
            account_count++;
            break;
        case 2:
            cout << "Enter account number : ";
            cin >> temp_account_number;
            for (i = 0; i < account_count; i++)
            {
                if (a[i].check(temp_account_number))
                {
                    a[i].deposit();
                    break;
                }
                else if (i == account_count - 1)
                {
                    cout << "ERROR : INVALID ACCOUNT NUMBER" << endl;
                }
            }
            break;
        case 3:
            cout << "Enter account number : ";
            cin >> temp_account_number;
            for (i = 0; i < account_count; i++)
            {
                if (a[i].check(temp_account_number))
                {
                    a[i].withdraw();
                    break;
                }
                else if (i == account_count - 1)
                {
                    cout << "ERROR : INVALID ACCOUNT NUMBER" << endl;
                }
            }
            break;
        case 4:
            cout << "Enter account number : ";
            cin >> temp_account_number;
            for (i = 0; i < account_count; i++)
            {
                if (a[i].check(temp_account_number))
                {
                    a[i].display_details();
                    break;
                }
                else if (i == account_count - 1)
                {
                    cout << "ERROR : INVALID ACCOUNT NUMBER" << endl;
                }
            }
            break;
        }

    } while (choice != 0);
    return 0;
}

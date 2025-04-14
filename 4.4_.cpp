
#include <iostream>
using namespace std;

class bankAccount{
    protected:
        int accountNumber,balance,previousBalance;
    public:
        bankAccount(int an,int b)
        {
            accountNumber=an;
            balance=b;
            previousBalance=balance;
        }
};

class SavingAccount: public bankAccount{
    private:
        float InterestRate;
    public:
        SavingAccount(int an,int b,float ir):bankAccount(an,b){
            InterestRate=ir;
            cout<<"Saving account created successfully!"<<endl;
        }
        void depositS(int amount){
            previousBalance=balance;
            balance+=amount;
            cout<<"Amount "<<amount<<" deposited successfully!"<<endl;
            cout<<"Current balance: "<<balance<<endl;
        }
        void withdrawS(int amount)
        {
            previousBalance=balance;
            balance-=amount;
            cout<<"Amount "<<amount<<" withdrawn successfully!"<<endl;
            cout<<"Current balance: "<<balance<<endl;
        }
        void undoS()
        {
            balance=previousBalance;
            cout<<"Undo done and current balance: "<<balance<<endl;
        }
};

class CurrentAccount: public bankAccount{
    private:
        int OverDraftLimit;
    public:
        CurrentAccount(int an,int b,int odl=0):bankAccount(an,b){
            OverDraftLimit=odl;
            cout<<"Cuurent account created succesfully!"<<endl;
        }
        void depositC(int amount){
            previousBalance=balance;
            balance+=amount;
            cout<<"Amount "<<amount<<" deposited successfully!"<<endl;
            cout<<"Current balance: "<<balance<<endl;
        }
        void withdrawC(int amount)
        {
            previousBalance=balance;
            if(amount>balance+OverDraftLimit)
            {
                cout<<"Amount is not enough to withdraw! Withdraw denied"<<endl;
            }
            else{
                balance-=amount;
                cout<<"Amount "<<amount<<" withdrawn successfully!"<<endl;
                cout<<"Current balance: "<<balance<<endl;
            }
        }
        void undoC()
        {
            balance=previousBalance;
            cout<<"Undo done and current balance: "<<balance<<endl;
        }
};

int main(){
    int an,b,odl,amount;
    float ir;

    int choice4CreatingAccount,choice4Transactions;
    cout<<"Enter 1 to create saving account\nEnter 2 to create current account\n";
    cout<<"Enter your choice: ";
    cin>>choice4CreatingAccount;

    switch(choice4CreatingAccount){
        case 1:{
            cout<<"Enter account number: ";
            cin>>an;
            cout<<"Enter initial balance: ";
            cin>>b;
            cout<<"Enter interest rate: ";
            cin>>ir;
            SavingAccount accountS(an,b,ir);
            do{
                cout<<"Enter 1 to Deposit amount\nEnter 2 to withdraw amount\nEnter 3 to undo last transaction\nEnter 0 to exit"<<endl;
                cout<<"Enter your choice: ";
                cin>>choice4Transactions;

                switch(choice4Transactions){
                    case 1:
                        cout<<"Enter amount to deposit: ";
                        cin>>amount;
                        accountS.depositS(amount);
                        break;
                    case 2:
                        cout<<"Enter amount to withdraw: ";
                        cin>>amount;
                        accountS.withdrawS(amount);
                        break;
                    case 3:
                        accountS.undoS();
                        break;
                    case 0:
                        cout<<"Thank you!"<<endl;
                        break;
                    default:
                        cout<<"Enter valid choice!"<<endl;
                }
            }while(choice4Transactions!=0);
        }
            break;
        case 2:{
            cout<<"Enter account number: ";
            cin>>an;
            cout<<"Enter initial balance: ";
            cin>>b;
            cout<<"Enter over draft limit: ";
            cin>>odl;
            CurrentAccount accountC(an,b,odl);
            do{
                cout<<"Enter 1 to Deposit amount\nEnter 2 to withdraw amount\nEnter 3 to undo last transaction\nEnter 0 to exit"<<endl;
                cout<<"Enter your choice: ";
                cin>>choice4Transactions;

                switch(choice4Transactions){
                    case 1:
                        cout<<"Enter amount to deposit: ";
                        cin>>amount;
                        accountC.depositC(amount);
                        break;
                    case 2:
                        cout<<"Enter amount to withdraw: ";
                        cin>>amount;
                        accountC.withdrawC(amount);
                        break;
                    case 3:
                        accountC.undoC();
                        break;
                    case 0:
                        cout<<"Thank you!"<<endl;
                        break;
                    default:
                        cout<<"Enter valid choice!"<<endl;
                }
            }while(choice4Transactions!=0);
        }
            break;
        default:
            cout<<"Enter valid choice! and try again"<<endl;
    }

    return 0;
}

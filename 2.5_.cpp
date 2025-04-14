#include <iostream>
#include <cmath>
using namespace std;

class Loan_Info
{
    int Loan_Id;
    string Applicant_Name;
    int Time_Period;
    int Total_Loan_Amount;
    double EMI;
    float Anual_Intrest;
    void EMI_Calculator(int amount ,int time , float intrest)
    {

        EMI = (amount*intrest*pow((1.0+intrest) , time))/(pow((1.0+intrest) , time) - 1);

    }
    public:
    void Get_Details()
    {
        cout<<"Enter Loan ID : ";
        cin>>Loan_Id;
        cout<<"Enter Applicant Name : ";
        cin>>Applicant_Name;
        cout<<"Enter total loan amount : ";
        cin>>Total_Loan_Amount;
        cout<<"Enter tenure of loan : ";
        cin>> Time_Period;
        cout<<"Enter Loan Interst : ";
        cin>>Anual_Intrest;
        EMI_Calculator(Time_Period , Total_Loan_Amount , Time_Period);
    }
    void Display_Details()
    {
        cout<<"Loan ID : "<<Loan_Id<<endl;
        cout<<"Applicant's Name : "<<Applicant_Name<<endl;
        cout<<"EMI : "<<EMI<<endl;

    }
};


int main()
{
    Loan_Info lf[50];
    int choice , Loan_count=0;
    do
    {
        cout<<"Enter 1 to add Loan details"<<endl;
        cout<<"Enter 2 to display detials"<<endl;
        cout<<"Enter 3 to EXIT"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1 :
                lf[Loan_count].Get_Details();
                Loan_count++;
                break;
            case 2:
                for(int i=0 ; i<Loan_count ; i++)
                {
                    lf[i].Display_Details();
                }
                break;
            case 0:
                cout<<"THANKS FOR VISITING"<<endl;
            default :
                cout<<"INVALID : CHOICE"<<endl;
                break;
        }
    }while(choice != 0);
    return 0;
}

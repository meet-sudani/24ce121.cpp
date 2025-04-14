
#include <iostream>
using namespace std;

class Student
{
    int roll_no;
    string name;
    int marks[3];
    public:
    Student()
    {
        roll_no = 0;
        name = "N.A";
        marks[0] = 0;
        marks[1] = 0;
        marks[2] = 0;
    }
    void get_details()
    {
        cout<<"Enter student roll number : ";
        cin >> roll_no;
        cout<<"Enter student name : ";
        cin >> name;
        cout << "Enter student marks"<<endl;
        cout<<"Maths : ";
        cin >> marks[0];
        cout <<"Physics : ";
        cin >> marks[1];
        cout<<"Chemistry : " ;
        cin >> marks[2];
    }
    void average()
    {
        cout<< ":::::::Marks obtained::::::::"<<endl;
        cout<<"Maths : "<<marks[0]<<endl;
        cout<<"Physics : "<<marks[1]<<endl;
        cout<<"Chemistry : "<<marks[2]<<endl;
        cout<<"Average : "<<((marks[0]+marks[1]+marks[2])/3)<< endl;
    }
    void display_details()
    {
        cout<<"ID : "<<roll_no<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Marks Obtained"<<endl;
        cout<<"Maths : "<<marks[0]<<endl;
        cout<<"Physcis : " << marks[1]<<endl;
        cout<<"Chmistry : "<<marks[2]<<endl;
    }
    int check(int roll)
    {
        if(roll_no== roll)
        {
            return 1;
        }
        else{
            return 0;
        }
    }
};


int main()
{
    Student s[10];
    int studentcount=0 , choice , temp;
    char x;
    do
    {
    cout<<"Enter 1 to add student"<<endl;
    cout<<"Enter 2 to dislpay Student average marks"<<endl;
    cout<<"Enter 3 to dislpay entire student deatils"<<endl;
    cout<<"Enter 0 to exit"<<endl;
    cout<<"Enter your choice : ";
    cin >>choice;
    switch(choice)
    {
        case 1:
            s[studentcount].get_details();
            studentcount++;
            break;

        case 2:
            cout<< "Enter student ID to display his/her average marks : " ;
            cin >> temp;
            for(int i=0 ; i<studentcount ; i++)
            {
                if( s[i].check(temp))
                {
                    s[i].average();
                    break;
                }
                else if(i==studentcount-1)
                {
                    cout<<"No matching id found"<<endl;
                }
            }
            break;
        case 3:

            cout<<"Enter student ID to dislpay his/her deatils : ";
            cin >> temp;
            for(int i=0 ; i<studentcount ; i++)
            {
                if( s[i].check(temp))
                {
                    s[i].display_details();
                    break;
                }
                else if(i==studentcount-1)
                {
                    cout<<"No matching id found"<<endl;
                }
            }
            break;
        case 0:
            cout<<"HAVE A GOOD DAY"<<endl;
            break;
        default :
            cout<<"Please retry"<<endl;
    }
}while(choice != 0);
    return 0;
}

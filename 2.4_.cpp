
#include <iostream>
using namespace std;

class Product
{
    int Product_Id;
    int Product_Quantity;
    string Product_Name;
    float Product_Price;
    int User_Quantitty=0;
    float display_Total(float price , int quantity)
    {
        return price*quantity;
    }
    public:
    void Add(int id , int quantitty,string name,float price)
    {
        Product_Id = id;
        Product_Quantity = quantitty;
        Product_Name = name;
        Product_Price = price;
    }
    int check(int idno)
        {
            cout<<"8";
            if(Product_Id == idno)
            {
                cout<<"9";
                return 1;
            }
            else
            {
                return 0;
            }
        }
    void update_Purchase()
    {
        User_Quantitty++;
        Product_Quantity--;
    }
    void update_Stockup(int quantitty)
    {
        Product_Quantity == Product_Quantity + quantitty;
    }
    void display_bill()
    {
        if( User_Quantitty > 0)
        {
            cout<<"ID : "<<Product_Id<<endl;
            cout<<"Name : "<<Product_Name<<endl;
            cout<<"Rate : "<<Product_Price<<endl;
            cout<<"Qantitiy : "<<User_Quantitty<<endl;
            cout<<"TOTAL : "<<display_Total(Product_Price, User_Quantitty)<<endl;
            User_Quantitty=0;
        }
    }
};

int main()
{
    Product p[10];
    int Product_count=0 , choice , Temp_Id , Temp_Quantity , choice2;
    float  Temp_Rate;
    string Temp_Name;
    do{
    cout<<"Enter 1 to add stock"<<endl;
    cout<<"Enter 2 to purchase item"<<endl;
    cout<<"Enter 0 to exit"<<endl;
    cout<<"Enter your choice : ";
    cin>>choice;
    if(choice == 1)
    {
        cout<<"Enter Product ID : ";
        cin>>Temp_Id;
        if(Product_count == 0)
        {
            cout<<"Enter product name :";
            cin>>Temp_Name;
            cout<<"Enter product rate : ";
            cin>>Temp_Rate;
            cout<<"Enter product Quantity : ";
            cin>>Temp_Quantity;
            Product_count++;
            p[0].Add(Temp_Id,Temp_Quantity,Temp_Name,Temp_Rate);
            cout<<"0";
        }
        else{
            for(int i=0; i<Product_count ; i++)
            {
                if(p[i].check(Temp_Id))
                {
                    p[i].update_Stockup(Temp_Quantity);
                    cout<<"Product Quantity Updated sucessflly"<<endl;
                    break;
                }
                else if(i == Product_count-1)
                {
                    cout<<"Enter product name :";
                    cin>>Temp_Name;
                    cout<<"Enter product rate : ";
                    cin>>Temp_Rate;
                    cout<<"Enter product Quantity : ";
                    cin>>Temp_Quantity;
                    p[Product_count].Add(Temp_Id,Temp_Quantity,Temp_Name,Temp_Rate);
                    Product_count++;
                    cout<<"1";
                }
            }
        }
    }
    else if(choice == 2)
    {
        do{
        cout<<"Enter 1 to purchase product"<<endl;
        cout<<"Enter 2 to display bill"<<endl;
        cout<<"Enter 0 to exit"<<endl;
        cout<<"Enter Your Choice : ";
        cin>>choice2;
        switch(choice2)
        {
            case 1 :
            cout<<"Enter product id : ";
            cin>>Temp_Id;
            for(int i=0; i<Product_count ; i++)
            {
                if(p[i].check(Temp_Id))
                {
                    p[i].update_Purchase();
                    break;
                }
                else if(i == Product_count-1)
                {
                    cout<<"NO product with matching id found"<<endl;
                }
            }
            break;
            case 2:
                for(int i=0 ; i<Product_count ; i++)
                {
                    p[i].display_bill();
                }
                break;
            case 0 :
                cout<<"Thank you for visiting"<<endl;
                break;
            default :
                cout<<"ERROR : INVALID CHOICE"<<endl;
                break;
        }
    }
        while(choice2 != 0);
    }
    else
    {
        cout<<"Invalid choice";
    }
}while(choice != 0);
    return 0;
}

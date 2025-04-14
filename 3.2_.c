
#include <iostream>
using namespace std;

void Sum_itrative(int array[],int size)
{
    int i,sum=0;
    for(i=0 ;i<size ; i++)
    {
        sum = sum+array[i];
    }
    cout<<"The sum through itrative aaporach is "<<sum<<endl;
}
int Sum_reccursive(int array[] , int size)
{
    if(size==0)
    {
        return 0;
    }
    else
    {
        return(array[size-1] + Sum_reccursive(array , size-1));
    }
}
int main()
{
    int size , *array,i,sum=0;
    cout<<"Enter the size of array you want : ";
    cin>>size;
    array = new int[size];
    cout<<"Enter numbers"<<endl;
    for(i=0 ; i<size ; i++)
    {
        cin>>array[i];
    }
    Sum_itrative(array , size);
    sum = Sum_reccursive(array , size);
    cout<<"The sum reccursive aaporach is "<<sum<<endl;
}

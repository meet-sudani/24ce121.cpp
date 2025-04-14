
#include <iostream>
using namespace std;

class Rectangle
 {
private:
    int length;
    int width;

public:

    void setDimensions(int l, int w)
    {

            length = l;
            width = w;

    }


    int area()
     {
        return length * width;
    }


    int perimeter()
     {
        return 2 * (length + width);
     }
};

int main()

{
    int n;
    cout<<endl<<"enter for how many rectangles you want to calculate data";
    cin>>n;

    Rectangle r[n];

 for(int i=0 ; i<n ; i++)
{


    int l, w;
    cout << "Enter length and width of the rectangle: ";
    cin >> l >> w;

    r[i].setDimensions(l, w);

    cout << "Area of the rectangle: " << r[i].area() << endl;
    cout << "Perimeter of the rectangle: " << r[i].perimeter() << endl;


}
    return 0;
}


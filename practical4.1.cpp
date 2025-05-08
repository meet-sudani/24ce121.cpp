
#include <iostream>
#include <string>
#include <queue>
using namespace std;

class FuelType
{

    protected:

        string fuel;

    public:

        FuelType(const string& fuelType) : fuel(fuelType) {}

    void showFuelType() const
    {
        cout << "Fuel Type: " << fuel << endl;
    }
};

class Brand
{
protected:

    string brandName;

public:
    Brand(const string& brand) : brandName(brand) {}

    void showBrandName() const
    {
        cout << "Brand: " << brandName << endl;
    }
};

class Car : public FuelType, public Brand
{
    private:
        string model;
    public:

        Car(const string& fuelType, const string& brand, const string& modelName)
        : FuelType(fuelType), Brand(brand), model(modelName) {}

    void displayDetails() const //i use const bcz i don`t chage value
    {
        showFuelType();
        showBrandName();
        cout << "Model: " << model << endl;
    }
};

int main()
{

    queue<Car> carQueue;


    carQueue.push(Car("Petrol", "Toyota", "Fortuner"));
    carQueue.push(Car("Diesel", "BMW", "330i M Sports"));
    carQueue.push(Car("Electric", "Mahindra", "BE 6"));


    while (!carQueue.empty())
    {
        Car currentCar = carQueue.front();
        carQueue.pop();
        currentCar.displayDetails();
        cout << "----------------------" << endl;
    }

    return 0;
}

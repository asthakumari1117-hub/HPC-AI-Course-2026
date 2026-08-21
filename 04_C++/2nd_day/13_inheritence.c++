#include<iostream>
using namespace std;

class Vehicle {
    protected:
    int tyres;
    public:
    void setTyres(int t)
    {
        tyres =t;
    }
};

class Bike : public Vehicle{
    public:
    void show()
    {
        cout<<"prediction : IT is a bike "<<endl;
    }
};

class Car : public Vehicle{
    public:
    void show()
    {
        cout<<"prediction : IT is a car "<<endl;
    }
};

class Truck : public Vehicle{
    public:
    void show()
    {
        cout<<"prediction : IT is a truck "<<endl;
    }
};

int main()
{
    int tyres;
    cout<<"Enter no of tyres : ";
    cin>> tyres;

    if(tyres == 2)
    {
        Bike b;
        b.setTyres(tyres);
        b.show();
    }

   else  if(tyres == 4)
    {
        Car c;
        c.setTyres(tyres);
        c.show();
    }

   else  if(tyres == 6)
    {
       Truck t;
        t.setTyres(tyres);
        t.show();
    }
    else
    {
        cout<< "Prediction : Vehicle type unknown "<<endl;
    }
    return 0;
}


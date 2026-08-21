#include<iostream>
using namespace std;

class Car
{
    private :
    int speed;
    string brand;

    public:
    void accelerate()
    {
        if(speed<120)
         speed+=10;
    }
    void brake()
    {
        if (speed>=10);
        speed -=10;
    }

    void setSpeed()
    {
        cout<< "enter speed in km/ \n";
        cin>>speed;
    }
     int getSpeed()
    {
          return speed;
    }


     void setBrand()
    {
        cout<< "enter Brand \n";
        cin>>brand;
    }

        void getBrand()
    {
        cout<< "Brand = "<<brand << endl;
    }

};

int main()
{
    Car car;
    car.setSpeed();
    car.setBrand();
    car.getBrand(); 
    car.accelerate();
    cout << "\n speed = "<<car.getSpeed()<<"km/h \n";
    car.accelerate();
    cout << "\n speed = "<<car.getSpeed()<<"km/h \n";
    return 0;
}
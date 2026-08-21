#include<iostream>
using namespace std;

class Car
{
    public:
    string brand;
    int speed;

    void accelerate()
    {
        speed+=10;
    }
    void showSpeed()
    {
        cout<< brand<< "speed = "<< speed << "km/h" <<endl;
    }
};

int main()
{
    Car car1;
    Car car2;

    car1.brand ="magnite";
    car1.speed = 120;

    car2.brand="siera";
    car2.speed =150;

    car1.accelerate();
    car2.accelerate();

    car1.showSpeed();
    car2.showSpeed();
    return 0;
}
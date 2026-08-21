#include<iostream>
using namespace std;

class Shape{
    public:
    int area (int side)
    {
        return side*side;
    }
    int area (int length,int breadth)
    {
        return length*breadth;
    }
    float area (float radius)
    {
        return 3.14f*radius*radius;
    }

};
int main()
{
    Shape s;
    cout<<"area of square = " <<s.area(5) <<endl;
    cout<<"area of Rectangle = " <<s.area(5,10) <<endl;
    cout<<"area of circle = " <<s.area(5.5f) <<endl;
return 0;
}
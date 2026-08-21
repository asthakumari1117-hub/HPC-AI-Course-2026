#include<iostream>
using namespace std;

class animal{
public:
void eat()
{
    cout<<"animal is eating "<<endl;
}
void sleep()
{
    cout<<"animal is sleeping "<< endl;
}
};

class Dog : public animal
{
    public:
    void bark()
    {
        cout<< "dog is barking " <<endl;
    }
};
int main()
{
    Dog shiro;
    shiro.eat();
    shiro.sleep();

    shiro.bark();
    return 0;

}
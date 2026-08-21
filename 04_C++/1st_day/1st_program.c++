#include<iostream>
using namespace std;

   struct student{
        int roll_no;
        float mrks;
        string name;
    };

    void add()
    {
        int sum;
        int a=10;
        int b=20;
        sum=a+b;
        cout<<sum<<endl;
        a++;
        cout<<a<<endl;
    }

int main()
{
    student s1;
    s1.roll_no=14;
    s1.mrks=53;
    s1.name="Astha";

    cout<<s1.roll_no <<endl;
    cout<<s1.mrks <<endl;
    cout<<s1.name <<endl;
    add();
    add();
    add();
    add();
}
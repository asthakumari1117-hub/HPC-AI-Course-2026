#include<iostream>
using namespace std;

int add()
{
    int a=10,b=20;
    return a+b;
}
int main()
{
    int result;
    result =add();
    cout << "sum ="<<result <<endl;

    return 0;
}
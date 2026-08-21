#include <iostream>
using namespace std;

void change(int *num)
{
    cout<<"value of num before adition = "<< *num <<"\n";
    (*num) +=100;
    cout<<"value after adding 100 ="<<*num <<"\n";
}
int main()
{
    int x=100;
    cout<<"value of x before fn called = "<< x << "\n";
    change(&x);
    cout << "value of x after fn called = "<<x <<"\n";
    return 0;
}
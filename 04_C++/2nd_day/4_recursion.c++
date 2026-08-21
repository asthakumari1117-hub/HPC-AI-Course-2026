#include<iostream>
using namespace std;

int factorial(int n)
{
    int fact;
    if(n==1)
    {
        return(1);
    }
    else{
        cout<<"this is layer"<<n<<endl;
        fact=n*factorial(n-1);
        return (fact);
    }

}
int main()
{
int a;
cout<<"enter the value\n";
cin>> a;
int result= factorial(a);
cout<<" \nfactorial ="<< result;
}
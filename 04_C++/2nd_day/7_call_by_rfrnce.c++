#include<iostream>
using namespace std;
void mathoperation(int x,int y,int z,int w,int *sum,int *mul);
int main()
{
    int x=20;
    int y=10;
    int w=30;
    int z=50;

    int sum,mul;
    cout<< "before fn call"<<endl;
    cout<<"x= "<<x<<"y= "<<y <<"z =" <<z <<"w ="<<w <<endl;
    mathoperation(x,y,z,w,&sum, &mul);
    cout<<"after fn call\n";
    cout<<"sum = " << sum<<endl;
    cout<<"multiplication = " <<mul << endl;
    return 0;
}

void mathoperation (int x,int y,int z,int w , int *sum,int *mul)
{
*sum=x+y+z+w;
*mul=x*y*z*w;
}
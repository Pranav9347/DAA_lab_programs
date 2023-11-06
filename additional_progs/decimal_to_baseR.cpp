/*Name: Pranav Vijay Nadgir
Roll no: CS22B1034*/

//decimal to base(R): max(R)=16
#include<iostream>
using namespace std;
void convert(int,int);

int main()
{   
    int n, R;
    cout<<"Enter the decimal number: ";
    cin>>n;
    cout<<"Enter base: ";
    cin>>R;
    cout<<"Its representation in base " <<R<<" is:";
    convert(n,R);
    

    return 0;
}
void convert(int n,int R)
{
    if(n<R)
    {
        if(n<10)
        cout<<n;
        if(n==10)cout<<"A";
        if(n==11)cout<<"B";
        if(n==12)cout<<"C";
        if(n==13)cout<<"D";
        if(n==14)cout<<"E";
        if(n==15)cout<<"F";
        return;
    }
    

    convert(n/R,R);
    if(n%R<10)
    cout<<n%R;
    else{
        if(n==10)cout<<"A";
        if(n==11)cout<<"B";
        if(n==12)cout<<"C";
        if(n==13)cout<<"D";
        if(n==14)cout<<"E";
        if(n==15)cout<<"F";
    }
}
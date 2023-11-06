#include<iostream>
using namespace std;

int Josephus(int n,int k=2)
{
    if(n==1)
        return 0;

    return (Josephus(n-1,k)+k)%n;
}

int main()
{
    int n;
    cin>>n;
    cout<<Josephus(n,2)+1;
}

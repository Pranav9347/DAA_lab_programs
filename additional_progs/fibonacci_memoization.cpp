//Program to determine the nth fibonacci number using memoization(top-down approach)
//It is called "top-down approach" because function call happens from higher n to lower n
#include<iostream>
using namespace std;

void fibonacci(int n, int* F)
{
    if(n <= 1)
    {
        F[n] = n;
    }
    else
    {
        if(F[n-1] == -1)
        fibonacci(n-1, F);
        if(F[n-2] == -1)
        fibonacci(n-2, F);
        F[n] = F[n-1]+F[n-2];
    }
    return;
}
int main()
{   
    int n;
    cout << "Enter n: ";
    cin >> n;
    if(n < 0){  cout << "n should be non-negative!\n";   return 0;   }

    //Declare an array of size n+1 and initialize all elements to -1:
    int* F = new int[n+1];//DMA is necessary(as n is variable)
    for(int i{0}; i < n+1; i++)
        F[i]=-1;
    fibonacci(n,F);
        cout << "The nth fibonacci number is: " << F[n] << endl;
    for(int x = F[0], i = 0; i < n+1; i++, x = F[i] )
        cout << x << " ";
    cout << endl;
    delete[] F;
    return 0;
}
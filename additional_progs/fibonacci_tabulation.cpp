//Program to determine the nth fibonacci number using tabulation(bottom-up approach)
//It is called "bottom-up approach" because fibonacci numbers are calculated from 0 to n
#include<iostream>
using namespace std;


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
    F[0] = 0;
    F[1] = 1;
    for(int i{2}; i < n+1; i++)
        F[i] = F[i-1]+F[i-2];
    cout << "The nth fibonacci number is: " << F[n] << endl;
    for(int x = F[0], i = 0; i < n+1; i++, x = F[i] )
        cout << x << " ";
    cout << endl;
    delete[] F;
    return 0;
}
#include<iostream>
using namespace std;
//Program to return box number containing 1.1 g coins, where the rest contain 1 g coins.
//Input: 1 Coin weight in each box in order, n<=10
int odd_box(double*,int);
int main()
{
    int n;
    cout<<"Enter array size:";
    cin>>n;
    double* arr = (double*) malloc(n*sizeof(double));
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    int x = odd_box(arr,n);
    cout<<"Box no. "<<x+1<<" contains coins of 1.1 grams";
    return 0;
}
int odd_box(double* A, int N)//O(1) comparisons
{ 
    double sum = 0;
    for(int i = 0; i < N; i++)
        sum = sum + (i+1)*A[i];
    if((sum - (int)sum) == 0)
        return 9;
    
    else 
    {
        return (10*(float)(sum - (int)sum))-1;
    }
}
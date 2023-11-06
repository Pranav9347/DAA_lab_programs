#include<iostream>
using namespace std;
//Program to return odd value in log(n) comparisons
//Input: array of non-negative integers with n-1 same elements and 1 different with higher value
int odd_value(int*, int);
int main()
{
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    int* arr = (int*) malloc(n*sizeof(int));
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    int x = odd_value(arr,n);
    if(x == -1)
    cout<<"Odd value does not exit";
    else cout<<"Odd value is: "<<x;
    return 0;
}
int odd_value(int* A, int N)
{
    int sum1 = 0, sum2 = 0;
    if(N % 2 == 0)
    {
        for(int i = 0; i < N/2; i++)
            sum1 = sum1 +  A[i];
        for(int i = N/2; i < N; i++)
            sum2 = sum2 +  A[i];
        
        //Termination conditions:
        if(sum1 == sum2)
            return -1;
        if((sum1 > sum2) && (N == 2) )
            return sum1;
        if((sum1 < sum2) && (N == 2) )
            return sum2;
        //Continue recursion:
        else if(sum1 > sum2)
            return odd_value(A, N/2);
        else return odd_value(A+(N/2), N/2);
    }
    else 
    {
        for(int i = 0; i < N/2; i++)
            sum1 = sum1 +  A[i];
        for(int i = N/2; i < N-1; i++)
            sum2 = sum2 +  A[i];

        //termination conditions:
        if((sum1 == sum2) && (A[N-1] != A[0]))
            return A[N-1];
        else if(sum1 == sum2)
            return -1;
        else if((sum1 > sum2) && (N == 3))
            return A[0];
        else if((sum2 > sum1) && (N == 3))
            return A[1];
        else if(sum1 > sum2)
            return odd_value(A, N/2);
        else return odd_value(A+(N/2),N/2);
        

    }
}
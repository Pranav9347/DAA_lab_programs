//Program to list all the n! permutations of an array of size n

#include<iostream>
using namespace std;

void permute(int*, int, int/*, int*/);
void swap(int*, int*);
void list_permutations(int*, int);

int main()
{   
    int *ptr, n;
    cout << "Enter array size: ";
    cin >> n;
    ptr = new int[n];
    cout << "Enter array elements: \n";
    for(int i{0}; i < n; i++)
        cin >> ptr[i];
    list_permutations(ptr,n);

    return 0;
}
void permute(int* ptr, int n, int var)
{
    static int numbering = 1;
    if(var == 1)//base case: print the array
    {
        cout << " [" << numbering << "] ";
        numbering++;
        for(int x{0}; x < n; x++)
            cout << ptr[x] << " ";
        cout << endl;
    }
    for(int i{0}; i < var-1; i++)
    {

        //Exploiting an interesting number pattern:*****
        if(var % 2 == 0 && i >= 2)//last var-3 times do this:
            swap(ptr+n-var, ptr+n-(i-1));
            else 
        swap(ptr+n-var,ptr+n-var+1);
        for(int j{0}; j < var-1; j++)
        {
            permute(ptr, n, j+1);
        }
    }
    return;
}
void swap(int* a, int* b)//no extra space
{
    *a = *a+*b;
    *b = *a-*b;
    *a = *a-*b;
    return;
}
void list_permutations(int* ptr, int n)
{
    for(int i{0}; i < n; i++)
        permute(ptr, n, i+1);
}
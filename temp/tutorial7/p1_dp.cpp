//Implementing coin change using tabulation:

#include<iostream>
#include<vector>
using namespace std;
int min(vector<int>);

int main()
{   
    int n, k;
    cout << "Enter the amount: ";
    cin >> n;
    cout << "Enter the number of denominations: ";
    cin >> k;
    if (n <= 0 || k <= 0) {
        cout << "Invalid input!" << endl;
        return 0;
    }
    vector<int> den(k);
    vector<int> C(n+1,n+1);
    for(int i{0}; i < k; i++)
    {
        cout << "denomination "<<i+1<<": ";
        cin >> den.at(i);
    }
    //Filling base case:
    C[0] = 0;
    vector<int> x(k,n+1);
    for(int i{1}; i < n+1; i++)
    {
        for(int j{0}; j < k; j++)
            if((i-den.at(j)>=0))
                x.at(j) = C[i-den.at(j)];
        
        C[i] = min(x)+1;
    }
    if(C[n] > n)
    {
        cout << "Change is not possible for "<< n << endl;
        return 0;
    }
    cout << "Minimum number of coins required to give change for "<<n<< " is: "<<C[n]<<endl;
    for(int i = C[0], j = 0; j < n + 1; j++, i = C[j]) 
        cout << i << " ";
    return 0;
}
int min(vector<int> x)
{
    int m = x.at(0);
    for(int i{1}; i < x.size(); i++)
    {
        if(m > x.at(i))
            m = x.at(i);
    }
    return m;
}
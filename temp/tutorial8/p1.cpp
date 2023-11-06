#include<iostream>
#include<vector>
using namespace std;


int Matrix_Chain(vector<int>p,int n)
{
    int memo[n][n];

    for(int i=0;i<n;i++)
        memo[i][i]=0;

    for(int len=2;len<n;len++)
    {
        for(int i=1;i<n-len+1;i++)
        {
            int j=i+len-1;
            memo[i][j]=INT_MAX;

            for(int k=i;k<j;k++)
            {
               int q=memo[i][k]+memo[k+1][j]+p[i-1]*p[k]*p[j];

                memo[i][j]=min(memo[i][j],q);
            }
        }
    }
    return memo[1][n-1];

}

int main()
{
    int n;
    cin>>n;
    vector<int> p(n);
    for(int i=0;i<n;i++)
        cin>>p[i];

   cout<< Matrix_Chain(p,n);
}

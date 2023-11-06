#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
   vector<pair<int,int>>v(n);
    int count=1;
    for(int i=0;i<n;i++)
    {
        cin>>v[i].first;
        v[i].second=i+1;
    }
    sort(v.begin(),v.end());
    int temp=-1;

    for(int i=0;i<n;++i)
    {
        if(v[i].second<temp)
        {
            count++;
        }
        temp=v[i].second;
    }

    cout<<count<<endl;
}

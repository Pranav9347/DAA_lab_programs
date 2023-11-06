//CS22B1064 AVINAASH.A
#include<iostream>
#include<vector>
using namespace std;

int find_Winner(vector<int>nums,int i,int j,int chance)
{
    if(i>j)
        return 0;

    if(chance==0)
        return max(nums[i]+find_Winner(nums,i+1,j,1),nums[j]+find_Winner(nums,i,j-1,1));
    else
        return min(find_Winner(nums,i+1,j,0),find_Winner(nums,i,j-1,0));
}



bool gold_Rush(vector<int> nums,int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=nums[i];

    int val=find_Winner(nums,0,n-1,0);
    sum=sum-val;
    return (val>=sum);
}

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];

    if(gold_Rush(nums,n))\
        cout<<"Player-1 wins"<<endl;
    else
        cout<<"Player-2 wins"<<endl;
}

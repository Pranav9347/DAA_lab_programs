#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    int count=0;
    int comp=0;
void Merge_array(int low,int mid,int high,vector<int>&nums)
{
    int left=low;
    int right=mid+1;
    vector<int> temp;
    while(left<=mid&&right<=high)
    {
        comp++;
        if(nums[left]>nums[right])
        {
            count+=(mid-left)+1;
            temp.push_back(nums[right]);
            right++;
        }
        else
        {
            temp.push_back(nums[left]);
            left++;
        }
    }
    if(right>high)
    {
        for(int i=left;i<=mid;i++)
            temp.push_back(nums[i]);
    }
    if(left>mid)
    {
        for(int i=right;i<=high;i++)
        {
            temp.push_back(nums[i]);
        }
    }
    for(int i=0;i<temp.size();i++)
    {
        nums[low+i]=temp[i];
    }


}




void Divide_array(int low,int high,vector<int>&nums)
{
       int mid=(low+high)/2;
    if(low<high)
    {
        Divide_array(low,mid,nums);
        Divide_array(mid+1,high,nums);
    }

    Merge_array(low,mid,high,nums);

}

};



int main()
{
    Solution obj;
    int n;
    cout<<"Enter the number of elements in the array:"<<endl;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }

    cout<<endl;
    obj.Divide_array(0,n-1,nums);
    cout<<"The number of inversion pairs is:"<<obj.count<<endl;

}

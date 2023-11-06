#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int minCut(string s) {
        int n=s.length();
        vector<int> memo(n,-1);
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++)
        dp[i][i]=true;
        for(int len=2;len<=n;len++)
        {
            for(int i=0;i<=n-len;i++)
            {
                int j=i+len-1;
                if(s[i]==s[j]&&(len==2||dp[i+1][j-1]))
                {
                    dp[i][j]=true;
                }
            }
        }
        return func(s,0,n,memo,dp)-1;

    }

    int func(string &s,int index,int n,vector<int>&memo,vector<vector<bool>>&dp)
    {
        int minSteps=INT_MAX;
        if(index==s.length())
        {
            return 0;
        }
        if(memo[index]!=-1)
        return memo[index];

        for(int i=index;i<n;i++)
        {
            if(dp[index][i]==true)
            {
                int steps=1+func(s,i+1,n,memo,dp);
                minSteps=min(steps,minSteps);
            }
        }
        memo[index]=minSteps;
        return minSteps;
    }


};


int main()
{
    Solution obj;
    string s;
    cout<<"Enter the string is:"<<endl;
    cin>>s;
    int result=obj.minCut(s);
    cout<<"The minimum number of cuts is:"<<result<<endl;
}


#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int>dp(amount+1,0);
         dp[0]=1;
        for(auto val:coins)
        {
            for(int i=val;i<=amount;i++)
            {
                dp[i]+=dp[i-val];
            }
        }
        return dp[amount];
    }
};



int main()
{
    int amount;
    cin>>amount;
    vector<int> coins;
    coins.push_back(1);
    coins.push_back(3);
    coins.push_back(4);
    Solution obj;
    cout<<obj.change(amount,coins);
}

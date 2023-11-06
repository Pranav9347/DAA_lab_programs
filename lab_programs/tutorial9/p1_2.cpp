#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        unordered_map<char,char>mp = {
            {']','['},
            {')','('},
            {'}','{'}
        };
      for(char ch:s){
          if(ch == '(' || ch== '[' || ch =='{')
              st.push(ch);
          else
          {
              if(st.empty() || st.top() != mp[ch])
              return false;
              st.pop();
          }
      }
      return st.empty();
    }
};


int main()
{
    string s;
    cin>>s;
    Solution obj;
    if(obj.isValid(s)==true)
        cout<<"Brackets are balanced"<<endl;
    else
        cout<<"Brackets are not balanced"<<endl;
}

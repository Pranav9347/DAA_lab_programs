#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 2) {
            return s;
        }

        int start = 0;  // Starting index of the longest palindrome.
        int maxlen = 1; // Length of the longest palindrome.

        int n = s.length();
        int** arr = new int*[n];

        for (int i = 0; i < n; i++) {
            arr[i] = new int[n];
            arr[i][i] = 1;  // All individual characters are palindromes.
        }

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                arr[i][i + 1] = 1;
                start = i;
                maxlen = 2;
            }
        }

       for(int len=3;len<=n;len++)
       {
           for(int i=0;i<=n-len;i++)
           {
               int j=i+len-1;

               if(s[i]==s[j]&&arr[i+1][j-1]==1)
               {
                   arr[i][j]=1;

                   if(len>maxlen)
                   {
                       maxlen=len;
                       start=i;
                   }
               }
           }
       }

        for (int i = 0; i < n; i++) {
            delete[] arr[i];
        }
        delete[] arr;

        return s.substr(start, maxlen);
    }
};

int main()
{
    Solution obj;
    string str;
    cout<<"Enter the string:"<<endl;
    cin>>str;
    string result=obj.longestPalindrome(str);
    cout<<"The result is:"<<result;
}

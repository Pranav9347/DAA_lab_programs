#include<bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<pair<int,int>> v;      //declaring a vector of pairs
    int n;

public:
    Solution(vector<pair<int,int>> v,int n)   //Paramterized Constructor
    {
        this->v=v;    //usage of this pointer to initialize v
        this->n=n;    //usage of this pointer to initialize n
    }
    Solution()
    {

    }
    void check_Reflexivity()  //O(N) time complexity to check if each element is related to each other
    {
        int count=0;
        for(int i=0;i<v.size();++i)
        {
            if(v[i].first==v[i].second)
                count++;
        }
        if(count==n)
            cout<<"Relation is Reflexive"<<endl;
        else
            cout<<"Relation is not Reflexive"<<endl;
    }
    void check_Symmetricity()  //O(NlogN) time complexity, because maps are implemented using Red Black Trees(self balancing trees) and take O(logN) time for searching.
    {
        map<pair<int,int>,int>m;
        for(int i=0;i<v.size();i++)
        {
            pair<int,int>p=v[i];
            m[p]++;
        }
        for(int i=0;i<v.size();i++)
        {
            pair<int,int>p=v[i];
            pair<int,int>p1;
            p1.first=p.second;
            p1.second=p.first;
            auto it=m.find(p1);
            if(it==m.end())
            {
                cout<<"Relation is not Symmetric"<<endl;
                return;
            }
        }
        cout<<"Relation is Symmetric"<<endl;
    }
    void check_Transitivity() //O(N^2logN)  //Search in map takes O(logN) time complexity
    {
        map<pair<int,int>,int>m;
        for(int i=0;i<v.size();i++)
        {
            m[v[i]]++;
        }
        for(int i=0;i<v.size();i++)
        {
            pair<int,int>p1=v[i];
            for(int j=i+1;j<v.size();j++)
            {
                pair<int,int>p2=v[j];
                if(p1.second==p2.first)
                {
                 pair<int,int>p;
                 p.first=p1.first;
                 p.second=p2.second;
                    auto it=m.find(p);
                    if(it==m.end())
                    {
                        cout<<"Relation is not Transitive"<<endl;
                        return;
                    }
                }
            }
        }
        cout<<"Relation is Transitive"<<endl;
    }
    void Iterative_Fibb(int n)
    {
       int f0=0;
       int f1=1;
       int f2;
       if(n==0)
       {
           cout<<f0<<endl;
           return;
       }
       else if(n==1)
       {
           cout<<f0<<" "<<f1<<endl;
           return;
       }
       n--;
       cout<<f0<<" "<<f1<<" ";
       while(n--)
       {
           f2=f0+f1;
           cout<<f2<<" ";
           f0=f1;
           f1=f2;

       }
         cout<<endl;
    }
};
int main()
{
    int choice;
    while(1)
{
   cout<<"1.Checking properties of a Binary Relation"<<endl<<"2.Iterative and Recursive Fibonacci\n"<<endl;
cin>>choice;
switch(choice)
{
   case 1:
       {
    vector<pair<int,int>>v;
 int n,val1,val2;
 cout<<"Enter the number of elements in the Set:"<<endl;
 cin>>n;
 cout<<"Enter the elements of the relation:(enter -1,-1 to terminate)"<<endl;
 while(true)
 {
     cin>>val1>>val2;
     if(val1==-1||val2==-1)
            break;
    pair<int,int>p={val1,val2};
     v.push_back(p);
 }

 Solution obj(v,n);

 obj.check_Reflexivity();
 obj.check_Symmetricity();
obj.check_Transitivity();
}
break;
   case 2:
    {
        int n;
         cin>>n;
         Solution obj;
         obj.Iterative_Fibb(n);
         //Recursive_Fibb(n);
    }
}
}




}

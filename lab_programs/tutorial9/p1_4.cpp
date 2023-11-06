#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution
{
    public:
    pair<int,int> longest_UniqueSong(vector<int> playlist)
    {
        unordered_map<int,int> mp;
        int len=0;
        int maxlen=0;
        int start=0;
        int bestStart=0;
        for(int i=0;i<playlist.size();i++)
        {
            int song=playlist[i];
            if(mp.find(song)!=mp.end()&&mp[song]>=start)
            {
                start=mp[song]+1;
                len=i-start+1;
            }
            else
            {
                len++;
            }
            mp[song]=i;
            if(len>maxlen)
            {
                maxlen=len;
                bestStart=start;
            }
        }
        return make_pair(bestStart,maxlen);
    }
};

int main()
{
    vector<int> playList;
    Solution obj;
    int n;
    cout<<"Size of the playlist:"<<endl;
    cin>>n;
    cout<<"Enter the playList"<<endl;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        playList.push_back(val);
    }
    pair<int,int> result=obj.longest_UniqueSong(playList);
    int len=result.second;
    int i=result.first;
    cout<<"Answer:"<<endl;
    while(len--)
    {
        cout<<playList[i];
        i++;
    }
    return 0;
}

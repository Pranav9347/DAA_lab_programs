// greedy: for k coins{r1,r2,...,rk}
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

void coin_change(vector<int>, int);

int main()
{   
    int amount, n;
    cout << "Enter the amount: ";
    cin >> amount;
    cout << "Enter the number of denominations: ";
    cin >> n;
    vector<int> denomination(n);
    for(int i{0}; i < n; i++)
    {
        cout << "Enter denomination " <<i+1 << ": ";
        cin >> denomination[i];
    }
    sort(denomination.begin(),denomination.end(), greater<int>());
    coin_change(denomination, amount);
    return 0;
}
void coin_change(vector<int> denomination, int amount)
{
    vector<int> num_of_coins(denomination.size());
    for(int i{0}; i < denomination.size(); i++)
    {
        while(amount >= denomination.at(i))
        {
            amount -= denomination.at(i);
            num_of_coins.at(i)++;
        }
        cout << "The number of coins of denomination " << denomination.at(i) << " is: "<<num_of_coins.at(i)<< endl;
    }
    return;
}
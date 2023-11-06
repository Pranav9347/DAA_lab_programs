#include <iostream>
#include <climits>
using namespace std;

int sum(int freq[], int i, int j);

int optimalSearchTree(int keys[], int freq[], int n) {
    int cost[n][n];

    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];

    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n - L + 1; i++) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;
            int offsetSum = sum(freq, i, j);

            for (int r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r - 1] : 0) +
                        ((r < j) ? cost[r + 1][j] : 0) +
                        offsetSum;
                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }
    return cost[0][n - 1];
}

int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++)
        s += freq[k];
    return s;
}

int main() {
    int n;
    cout << "Enter the number of keys: ";
    cin >> n;

    int keys[n];
    int freq[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter key " << i + 1 << ": ";
        cin >> keys[i];
        cout << "Enter frequency for key " << i + 1 << ": ";
        cin >> freq[i];
    }

    cout << "Cost of Optimal BST is " << optimalSearchTree(keys, freq, n) << endl;
    return 0;
}

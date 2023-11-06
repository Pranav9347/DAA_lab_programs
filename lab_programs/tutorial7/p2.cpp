#include <iostream>
#include <vector>
#include <climits> // for INT_MAX
using namespace std;

int min(int a, int b) {
    return (a < b) ? a : b;
}

int coinChange(vector<int>& den, int n, vector<int>& l) {
    int k = den.size();
    vector<vector<int>> C(k + 1, vector<int>(n + 1, INT_MAX));
    
    for (int i = 0; i <= k; i++) {
        C[i][0] = 0;
    }

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            if (den[i - 1] <= j && l[i - 1] > 0) {
                C[i][j] = min(C[i - 1][j], C[i][j - den[i - 1]] + 1);
                l[i - 1]--;
            } else {
                C[i][j] = C[i - 1][j];
            }
        }
    }

    return (C[k][n] == INT_MAX) ? -1 : C[k][n];
}

int main() {
    int n, k;
    cout << "Enter the amount: ";
    cin >> n;
    cout << "Enter the number of denominations: ";
    cin >> k;

    if (n <= 0 || k <= 0) {
        cout << "Invalid input!" << endl;
        return 0;
    }

    vector<int> den(k);
    vector<int> l(k);

    for (int i = 0; i < k; i++) {
        cout << "Denomination " << i + 1 << ": ";
        cin >> den[i];
        cout << "Maximum number of coins available for this denomination: ";
        cin >> l[i];
    }

    int result = coinChange(den, n, l);

    if (result == -1) {
        cout << "Change is not possible for " << n << endl;
    } else {
        cout << "Minimum number of coins required to give change for " << n << " is: " << result << endl;
    }

    return 0;
}

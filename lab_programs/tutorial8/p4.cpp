#include <iostream>
#include <vector>
#include <string>

using namespace std;

string findLCS(const string& X, const string& Y) {
    int m = X.length();
    int n = Y.length();

    // Create and initialize a 2D table to store LCS lengths
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Build the dp table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstruct the LCS
    string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs = X[i - 1] + lcs;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return lcs;
}

int main() {
    string X = "ABCBDAB";
    string Y = "BDCAB";

    string lcs = findLCS(X, Y);

    cout << "Longest Common Subsequence: " << lcs << endl;

    return 0;
}
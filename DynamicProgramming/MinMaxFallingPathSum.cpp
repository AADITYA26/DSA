#include <bits/stdc++.h>
using namespace std;

//---------------------------------------------------------------
// RECURSION
//---------------------------------------------------------------

int solve(int i, int j, vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    // Out of bounds
    if (j < 0 || j >= m)
        return 1e9;

    // Reached last row
    if (i == n - 1)
        return matrix[i][j];

    int down = matrix[i][j] + solve(i + 1, j, matrix);
    int leftDiag = matrix[i][j] + solve(i + 1, j - 1, matrix);
    int rightDiag = matrix[i][j] + solve(i + 1, j + 1, matrix);

    return min({down, leftDiag, rightDiag});
}

int minFallingPathSum_Rec(vector<vector<int>> &matrix) {
    int m = matrix[0].size();

    int ans = 1e9;

    // Try every starting column
    for (int j = 0; j < m; j++)
        ans = min(ans, solve(0, j, matrix));

    return ans;
}


//---------------------------------------------------------------
// MEMOIZATION
//---------------------------------------------------------------

int solveMemo(int i, int j, vector<vector<int>> &matrix,
            vector<vector<int>> &dp) {

    int n = matrix.size();
    int m = matrix[0].size();

    if (j < 0 || j >= m)
        return 1e9;

    if (i == n - 1)
        return matrix[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int down = matrix[i][j] + solveMemo(i + 1, j, matrix, dp);
    int leftDiag = matrix[i][j] + solveMemo(i + 1, j - 1, matrix, dp);
    int rightDiag = matrix[i][j] + solveMemo(i + 1, j + 1, matrix, dp);

    return dp[i][j] = min({down, leftDiag, rightDiag});
}

int minFallingPathSum_Memo(vector<vector<int>> &matrix) {

    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    int ans = 1e9;

    for (int j = 0; j < m; j++)
        ans = min(ans, solveMemo(0, j, matrix, dp));

    return ans;
}


//---------------------------------------------------------------
// TABULATION
//---------------------------------------------------------------

int minFallingPathSum_Tab(vector<vector<int>> &matrix) {

    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Base case: last row
    for (int j = 0; j < m; j++)
        dp[n - 1][j] = matrix[n - 1][j];

    // Fill from bottom to top
    for (int i = n - 2; i >= 0; i--) {

        for (int j = 0; j < m; j++) {

            int down = dp[i + 1][j];

            int leftDiag = 1e9;
            if (j > 0)
                leftDiag = dp[i + 1][j - 1];

            int rightDiag = 1e9;
            if (j < m - 1)
                rightDiag = dp[i + 1][j + 1];

            dp[i][j] = matrix[i][j] +
                    min({down, leftDiag, rightDiag});
        }
    }

    // Answer is minimum in first row
    return *min_element(dp[0].begin(), dp[0].end());
}


//---------------------------------------------------------------
// SPACE OPTIMIZATION
//---------------------------------------------------------------

int minFallingPathSum_Optimal(vector<vector<int>> &matrix) {

    int n = matrix.size();
    int m = matrix[0].size();

    // Previous row = row below current row
    vector<int> prev = matrix[n - 1];

    for (int i = n - 2; i >= 0; i--) {

        vector<int> curr(m);

        for (int j = 0; j < m; j++) {

            int down = prev[j];

            int leftDiag = 1e9;
            if (j > 0)
                leftDiag = prev[j - 1];

            int rightDiag = 1e9;
            if (j < m - 1)
                rightDiag = prev[j + 1];

            curr[j] = matrix[i][j] +
                    min({down, leftDiag, rightDiag});
        }

        prev = curr;
    }

    return *min_element(prev.begin(), prev.end());
}
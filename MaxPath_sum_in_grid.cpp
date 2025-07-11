// User function Template for C++

class Solution
{
public:
    // recursion + Memoization
    int f(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
    {
        // base case - out of bounds - return something that gets ignored
        if (j < 0 || j >= mat[0].size())
            return -1e8;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (i == 0) // if we reach any cell of first row we have arrived at our destination
            return mat[0][j];

        int up = mat[i][j] + f(i - 1, j, mat, dp);
        int leftdiag = mat[i][j] + f(i - 1, j - 1, mat, dp);
        int rightdiag = mat[i][j] + f(i - 1, j + 1, mat, dp);

        return dp[i][j] = max(up, max(leftdiag, rightdiag));
    }

    int maximumPath(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        int maxi = -1e8;
        for (int j = 0; j < m; j++)
        {
            maxi = max(maxi, f(n - 1, j, mat, dp));
        }
        return maxi;
    }
};

int maximumPath(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    //! Bottom UP approach
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int j = 0; j < m; j++)
        dp[0][j] = mat[0][j];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = mat[i][j] + dp[i - 1][j];

            int leftdiag = mat[i][j];

            if (j - 1 >= 0)
                leftdiag += dp[i - 1][j - 1];

            else
                leftdiag += -1e8;

            int rightdiag = mat[i][j];
            if (j + 1 < m)
                rightdiag += dp[i - 1][j + 1];

            else
                rightdiag += -1e8;

            dp[i][j] = max(up, max(leftdiag, rightdiag));
        }
    }

    int maxi = -1e8;
    for (int j = 0; j < m; j++)
    {
        if (n > 0)
            maxi = max(maxi, dp[n - 1][j]);
    }
    return maxi;
}
}
;

// Space optimization
int maximumPath(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    vector<int> prev(m, 0), curr(m, 0);

    for (int j = 0; j < m; j++)
        prev[j] = mat[0][j];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = mat[i][j] + prev[j];

            int leftdiag = mat[i][j];

            if (j - 1 >= 0)
                leftdiag += prev[j - 1];

            else
                leftdiag += -1e8;

            int rightdiag = mat[i][j];
            if (j + 1 < m)
                rightdiag += prev[j + 1];

            else
                rightdiag += -1e8;

            curr[j] = max(up, max(leftdiag, rightdiag));
        }
        prev = curr;
    }

    int maxi = -1e8;
    for (int j = 0; j < m; j++)
    {
        if (n > 0)
            maxi = max(maxi, prev[j]);
    }
    return maxi;
}
}
;
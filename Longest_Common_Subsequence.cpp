class Solution
{
public:
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {

        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        // char match move both of the indexes
        if (s[i] == t[j])
        {

            return dp[i][j] = 1 + f(i - 1, j - 1, s, t, dp);
        }

        // char at idx dont match - move either of the index and return max
        return dp[i][j] = max(f(i - 1, j, s, t, dp), f(i, j - 1, s, t, dp));
    }

    int lcs(string &s1, string &s2)
    {
        // code here
        // memoization
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, s1, s2, dp);
    }
};

class Solution
{
public:
    int longestCommonSubsequence(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        // bottom  up apporach
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int j = 0; j <= m; j++)
            dp[0][j] = 0;

        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {

                if (s[i - 1] == t[j - 1]) // char match // move index of both
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else // char doesnt match move either indexes of strings
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};

#include <bits/stdc++.h>
int lcs(string s, string t)
{
    // Write your code here
    int n = s.size();
    int m = t.size();

    vector<int> prev(m + 1, 0);
    vector<int> curr(m + 1, 0);
    // Space Optimized
    for (int j = 0; j <= m; j++)
        prev[j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }
    return prev[m];
}
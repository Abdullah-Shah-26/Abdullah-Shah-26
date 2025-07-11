// User function Template for C++

class Solution
{
public:
    // Longest Common Subseq bottom up approach
    int LCS(string s, string t)
    {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // we are using 1 based indexing so
        for (int j = 0; j <= m; j++)
            dp[0][j] = 0;

        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                // if char match move index of both and new len = 1 + max of prev found LPS len
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else // char doesntt match move indexes of either of strings
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }

    class Solution
    {
    public:
        int LCS(string s, string t)
        {
            int n = s.size();
            int m = t.size();

            vector<int> prev(m + 1, 0);
            vector<int> curr(m + 1, 0);

            // space Optimized

            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    // match found then len = 1 + prev max len of LCS
                    if (s[i - 1] == t[j - 1])
                        curr[j] = 1 + prev[j - 1];
                    else // char match not found- move index of eithr of them and return max
                        curr[j] = max(prev[j], curr[j - 1]);
                }
                prev = curr;
            }
            return prev[m];
        }

        int longestPalindromeSubseq(string s)
        {
            // we can use LCS and find common between given string and reversed string - LPS
            string t = s;
            reverse(s.begin(), s.end());
            return LCS(s, t);
        }
    };
class Solution
{
public:
    string shortestCommonSupersequence(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        // LCS CODE -
        // converted to 1 based indexing since dp can't have -ve
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int j = 0; j <= m; j++)
            dp[0][j] = 0;
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                // if char match add 1 + max len up until prevously matched char
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                else /// if they didnt match ans is max of up or left
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        // len of supersequence = n + m - len(LCS)
        string ans = "";

        int i = n;
        int j = m;

        while (i > 0 && j > 0)
        {
            // if they match add char in ans and move diagonally
            if (s[i - 1] == t[j - 1])
            {
                ans += s[i - 1];
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                // move up
                ans += s[i - 1];
                i--;
            }
            else // move left
            {
                ans += t[j - 1];
                j--;
            }
        }

        // if one of the string gets exhausted add other ones char
        while (i > 0)
        {
            ans += s[i - 1];
            i--;
        }

        while (j > 0)
        {
            ans += t[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
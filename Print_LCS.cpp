#include <bits/stdc++.h>
#include <string>
using namespace std;

void lcs(string s, string t)
{
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;
    for (int i = 1; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];

            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int len = dp[n][m];
    string ans = "";

    for (int i = 0; i < len; i++)
    {
        // storing dummy char in ans
        ans += '$';
    }

    int index = len - 1;

    int i = n;
    int j = m;

    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            // if char match in both strings go diagonal in dp and add that char in ans
            ans[index] = s[i - 1];
            index--;
            i--;
            j--;
        }
        // if char dont match go to top or bottom which ever is max
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    cout << ans;
}

class Solution
{
public:
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        // s2 get exhausted means we found all its occurences in s1
        if (j < 0)
            return 1;
        // if s1 gets exhauseted before checking s2 in it
        if (i < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        // Char match
        if (s[i] == t[j])
        {
            return dp[i][j] = f(i - 1, j - 1, s, t, dp) + f(i - 1, j, s, t, dp); // we are taking diff combinations of same char at diffent positions
        }

        // char of s2 not found in s1 then movve idx in s1
        return dp[i][j] = f(i - 1, j, s, t, dp);
    }

    int numDistinct(string s, string t)
    {
        // recursion + Memoization
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, s, t, dp);
    }
};

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        // BOTTOM UP APPROACH
        int n = s.size();
        int m = t.size();
        // change to 1 based indexing  like done in lcs since dp cant handle -ve
        vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));

        // base case
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1; // since j = 0 means s2 exhausted and we found all occurences of it in s1
        for (int j = 1; j <= m; j++)
            dp[0][j] = 0; // reverse of above

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {

                // Char match
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]; // we are taking diff combinations of same char at diffent positions
                }
                else // char of s2 not found in s1 then movve idx in s1
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return (int)dp[n][m];
    }
};

class Solution {
public:
    int numDistinct(string s, string t) {
    // Super Space optimization
     int n = s.size();
     int m = t.size();
// change to 1 based indexing  like done in lcs since dp cant handle -ve
vector<double>prev(m + 1, 0);

// initializing the 0 th col of prev and curr with 1
prev[0]= 1;

    for(int i =1 ; i <=n ; i++)
    {
        for(int j =m; j>= 1 ;j--)
        {

    // Char match 
    if(s[i-1] == t[j-1])
    {
         prev[j] = prev[j-1]+ prev[j]; // we are taking diff combinations of same char at diffent positions 
    }
 
        }
    }
return (int)prev[m];

    }
};
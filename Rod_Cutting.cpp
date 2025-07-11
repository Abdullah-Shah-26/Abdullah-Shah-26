class Solution
{
public:
    // memoization
    int f(int idx, int N, vector<int> &price, vector<vector<int>> &dp)
    {
        // base case - only 1 option to cut rod so price = n * rodlength
        if (idx == 0)
            return N * price[0];

        if (dp[idx][N] != -1)
            return dp[idx][N];

        int nottake = 0 + f(idx - 1, N, price, dp);
        int take = INT_MIN;
        int rodlength = idx + 1;
        // since we can use same rod multiple times we arent updating idx
        if (rodlength <= N)
            take = price[idx] + f(idx, N - rodlength, price, dp);

        return dp[idx][N] = max(take, nottake);
    }
    int cutRod(vector<int> &price)
    {
        // code here
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(n - 1, n, price, dp);
    }
};

// Tabulation
class Solution
{
public:
    int cutRod(vector<int> &price)
    {
        // code here
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        for (int N = 0; N <= n; N++)
        { // base case
            dp[0][N] = N * price[0];
        }

        for (int idx = 1; idx < n; idx++)
        {
            for (int N = 0; N <= n; N++)
            {

                int nottake = 0 + dp[idx - 1][N];
                int take = INT_MIN;
                int rodlength = idx + 1;
                // since we can use same rod multiple times we arent updating idx
                if (rodlength <= N)
                    take = price[idx] + dp[idx][N - rodlength];

                dp[idx][N] = max(take, nottake);
            }
        }
        return dp[n - 1][n];
    }
};

// space optimizationclass Solution {
public:
int cutRod(vector<int> &price)
{
    int n = price.size();
    vector<int> prev(n + 1, 0), curr(n + 1, 0);

    // base case
    for (int N = 0; N <= n; N++)
    {
        prev[N] = N * price[0];
    }

    for (int idx = 1; idx < n; idx++)
    {
        int rodlength = idx + 1;
        for (int N = 0; N <= n; N++)
        {
            int notTake = prev[N];
            int take = INT_MIN;
            if (rodlength <= N)
                take = price[idx] + curr[N - rodlength];
            curr[N] = max(take, notTake);
        }
        prev = curr; // update for next round
    }

    return prev[n];
}
}
;

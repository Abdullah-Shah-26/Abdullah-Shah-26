class Solution {
public:
//! Top DOWN APPROACH
int count(int i , int n, vector<int>&dp)
{
    if(i == n)
    return 1;

    if(i > n)
    return 0;

    // if already result is stored dont calculate again
    if(dp[i] != -1)
    return dp[i];
    
    // store the results while returning 
    return dp [i] = count(i+1, n, dp) + count(i+2, n, dp);
}

    int climbStairs(int n) {
        vector<int>dp(n+2, -1);
        return count(0,n,dp);
    }
};
//!-----------------------------------------------------------------------------
class Solution {
public:

    int climbStairs(int n) {
        vector<int>dp(n+2, -1);
        //! Bottom Up
        // Fill base case first 
        dp[n] = 1;
        dp[n+1] = 0;

    // reverse of top down 
        for(int i = n-1; i>= 0; i--)
        dp[i] = dp[i + 1] + dp[i+2];

        return dp[0];
    }
};
//!-----------------------------------------------------------------------------
class Solution {
public:

    int climbStairs(int n) {
        vector<int>dp(n+2, -1);
        //! space optimization  - TC = O(N) SC = O(1)
        int curr , int next = 1, int next2 = 0;

        for(int i = n - 1; i >= 0; i--)
        {
            curr = next + next2;
            next2 = next;
            next = curr;
        }
        return curr;
    }
};
class Solution {
public:
//! Top Down Approach
int dp[301][5001]; // according to question constraints
int find(int idx, int amt , vector<int> &coins, int n)
{
    // Base case
    if(amt == 0)
    return 1;

    if(amt < 0 || idx >= n)
    return 0;

    // if value is already calculated return it 
    if(dp[idx][amt] != -1)
    return dp[idx][amt];
    
    // store the result before returning
    // coin use kiya                              // coin use nahi kiya
    return dp[idx][amt] = find(idx, amt - coins[idx],coins ,n) + find(idx + 1, amt, coins, n);
}
    int change(int amt, vector<int>& coins) {
        int n = coins.size();
        memset(dp, -1, sizeof(dp));
        return find(0, amt, coins, n);
    }
};
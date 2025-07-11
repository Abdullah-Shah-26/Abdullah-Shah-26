class Solution {
public:
// ! BOTTOM UP APPROACH
int f(int idx, vector<int>&coins, int amt , vector<vector<int>> &dp)
{
    // Base Case
    if(idx == 0)
    {
        if(amt % coins[0] == 0)
        return amt/coins[0];
        else 
        return 1e9;
    }

    if(dp[idx][amt] != -1)
    return dp[idx][amt];

    int nottake = 0 + f(idx-1, coins, amt, dp);
    int take = 1e9;
    if(coins[idx] <= amt)
    {
        take = 1 + f(idx, coins, amt- coins[idx], dp);
    }

    return dp[idx][amt] = min(take, nottake);
}
    int coinChange(vector<int>& coins, int amt) {
        int n = coins.size();
        vector<vector<int>>dp(n , vector<int>(amt + 1, 0));
        
        for(int a = 0; a <= amt ; a++)
        {
            if(a % coins[0] == 0)
            dp[0][a] = a/coins[0];
            else 
            dp[0][a] = 1e9;
        }

        for(int idx = 1; idx <n; idx++)
        {
            for(int a = 0; a <= amt ; a++)
            {
                int nottake = 0 + dp[idx-1][a];

                int take = 1e9;
                
                if(coins[idx] <= a)
                {
                    take = 1 + dp[idx][a - coins[idx]];
                }
                dp[idx][a] = min(take , nottake);
                
            }
        }
    

        int ans = dp[n-1][amt];
        if(ans >= 1e9)
        return -1;
        else 
        return ans;
    }


};

class Solution {
  public:
    int count(vector<int>& nums, int target) {
        // code here.
        // space optimized
        
        vector<int>prev(target +1, 0), curr(target +1, 0);
        
        int n = nums.size();
        
        // BASE case
        for(int T = 0; T <= target ; T++)
        {
            if(T % nums[0] == 0)// if its divisible store how many times we need totake it
            prev[T] = T/nums[0];
            else
            prev[T] = 1e9;
        }
        
        for(int idx = 1; idx< n;  idx++)
        {
            for(int T = 0; T <= target; T++)
            {
                int nottake = 0 + prev[T];
                
                int take = 1e9;
                if(nums[idx] <= T)
                {
                    take = 1 + curr[T - nums[idx]];
                }
                curr[T] = min(take , nottake);
            }
            prev = curr;
        }
    // note
    int ans = prev[target];
    
return ans >= 1e9 ? -1 : ans;
    }
};
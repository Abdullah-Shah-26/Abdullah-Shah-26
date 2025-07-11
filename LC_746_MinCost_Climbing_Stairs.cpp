class Solution {
public:
// Top Down Approach 
    int ways(int n , vector<int>& cost, vector<int> &dp)
    {
        if(n <= 1)
        return 0;
        
        // if result is already calculated return it
        if(dp[n] != -1)
        return dp[n];

        return min(cost[n-1] + ways(n-1, cost, dp), cost[n-2] + ways(n-2, cost, dp));
    }


    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n + 1, -1);
        return ways(n, cost, dp);
    }
};

//!-----------------------------------------------------------------------------
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n + 1, -1);
       //! Bottom Up 
       // base case 
       // we only have to pay when we move from this not when we stand on 0/1st stair
       dp[0] = 0; 
       dp[1] = 0;

       for(int i = 2; i <= n; i++)
       {
        dp[i] = min(cost[i-1] + dp[i-1], cost[i-2] + dp[i-2]);
       }
       return dp[n];
    }
};
//!-----------------------------------------------------------------------------
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n + 1, -1);
       //! Space optimization
       // we only have to pay when we move from this not when we stand on 0/1st stair
        int prev = 0; 
        int prev1 = 0, curr;

       for(int i = 2; i <= n; i++)
       {
        curr = min(cost[i-1] + prev, cost[i-2] + prev1);
        prev1 = prev;
        prev = curr;
       }
    return curr;
    }
};

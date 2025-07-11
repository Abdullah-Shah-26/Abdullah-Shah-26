class Solution {
  public:
  // Recursion + Memoization
  int f(int idx, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
  {
     // Base case
     if(idx == 0)
     {
         // if we have one idx and its wt is <= the capacity of thiefs bag take it
         if(wt[0] <= W)
         return val[0];
         
         return 0;
     }
     
     if(dp[idx][W] != -1)
     return dp[idx][W];
     
     int nottake = 0 + f(idx -1, W, wt, val, dp);
     int take = INT_MIN;
     
     if(wt[idx] <= W) //  if wt comes under thief bags take it else leave it
     take = val[idx] + f(idx -1, W - wt[idx],wt,  val , dp);
     
     return dp[idx][W] = max(take, nottake);
  }
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        
        vector<vector<int>>dp(val.size(), vector<int>(W + 1, -1));
        return f(val.size()-1, W, wt, val, dp);
    }
};



#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// BOTTOM UP APPROACH 
	vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

	for(int w = weight[0]; w <= maxWeight; w++)
	{
		dp[0][w] = value[0];
	}

	for(int idx = 1; idx < n ; idx++)
	{
		for(int W = 0; W <= maxWeight; W++)
		{
			int notTake = 0 + dp[idx -1][W];

			int take = INT_MIN;
			if(weight[idx] <= W)
			{
				take = value[idx] + dp[idx -1 ][W - weight[idx]];
			}
		dp[idx][W] = max(take, notTake);
		}
	}
return dp[n-1][maxWeight];
}

int Solution::solve(vector<int> &val, vector<int> &wt, int maxwt) {
    vector<int>prev(maxwt+1, 0);
    vector<int>curr(maxwt +1, 0);
    //! Spacee Optimized Code
    for(int W = wt[0] ; W <= maxwt; W++)
    prev[W] = val[0];
    
    for(int idx = 1; idx < val.size(); idx++)
    {
        for(int W = 0; W <= maxwt ; W++)
        {
            int notTake = 0 + prev[W];
            int take = INT_MIN;
            
            if(wt[idx] <= W)
            take = val[idx] + prev[W- wt[idx]];
            
            curr[W] = max(take, notTake);
        }
        prev = curr;
    }
return prev[maxwt];
}


//!  Single array Space Optimization
 int Solution::solve(vector<int> &val, vector<int> &wt, int maxwt) {
    vector<int>prev(maxwt+1, 0);
    
    for(int W = wt[0] ; W <= maxwt; W++)
    prev[W] = val[0];
    
    for(int idx = 1; idx < val.size(); idx++)
    {//! instead of going L to R we will go R to L and overwrite prev values repeatedly instead of creating a curr
        for(int w = maxwt ; w >= wt[0]; w--)
        {
            int notTake = 0 + prev[W];
            int take = INT_MIN;
            
            if(wt[idx] <= W)
            take = val[idx] + prev[W- wt[idx]];
            
            prev[W] = max(take, notTake);
        }
    

    }
return prev[maxwt];
}
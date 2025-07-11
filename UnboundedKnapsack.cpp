// User function Template for C++
// recursion + memo
class Solution {
  public:
  
  int f(int idx, int W, vector<int>&val, vector<int> &wt, vector<vector<int>> &dp)
    {
    // Base Case
    if(idx == 0)
    {
        return (W/wt[0])*val[0];
    }
    if(dp[idx][W] != -1)
    return dp[idx][W];
    
    int nottake = 0 + f(idx  -1, W, val, wt, dp);
    int take = INT_MIN;
    
    if(wt[idx] <= W)
    {   // not updating idx since we can take same wt multiple times
        take = val[idx] + f(idx , W - wt[idx] , val , wt, dp);
    }
   
    return dp[idx][W] =  max(take , nottake);
    
    }
  
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<vector<int>>dp(n, vector<int>(capacity +1, -1));
        return f(n-1, capacity, val , wt, dp);
    }
};


#include<bits/stdc++.h>
using namespace std;
int unboundedKnapsack(int n, int W, vector<int> &val, vector<int> &wt){
    if(n == 0 || W == 0) return 0;
    vector<int> prev(W+1, 0);
    for(int w = 0; w <= W; w++)
        prev[w] = (wt[0] != 0) ? (w / wt[0]) * val[0] : 0;

    for(int i = 1; i < n; i++){
        vector<int> curr(W+1, 0);
        for(int w = 0; w <= W; w++){
            int nottake = prev[w];
            int take = (wt[i] <= w) ? val[i] + curr[w - wt[i]] : INT_MIN;
            curr[w] = max(take, nottake);
        }
        prev = curr;
    }
    return prev[W];
}

// Spaced Optimized to 1 array
#include<bits/stdc++.h>
using namespace std;
int unboundedKnapsack(int n, int W, vector<int> &val, vector<int> &wt){
    if(n == 0 || W == 0) return 0;
    vector<int> prev(W+1, 0);
    for(int w = 0; w <= W; w++)
        prev[w] = (wt[0] != 0) ? (w / wt[0]) * val[0] : 0;

    for(int i = 1; i < n; i++){
       
        for(int w = 0; w <= W; w++){
            int nottake = prev[w];
            int take = (wt[i] <= w) ? val[i] + prev[w - wt[i]] : INT_MIN;
            prev[w] = max(take, nottake);
        }
    
    }
    return prev[W];
}
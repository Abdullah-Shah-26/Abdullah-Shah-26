class Solution {
public:
// This code is for finding the minimum cost path in a grid from the top-left corner to the bottom-right corner
// using recursion with memoization.
  int f(int i , int j , vector<vector<int>>&grid, vector<vector<int>> &dp)
  {
      // add destination s cost
      if(i == 0 && j == 0)
      return grid[i][j];
      
      // edge case out of bounds return something that will be ignored
      if(i < 0 || j < 0)
      return 1e9;
      
      if(dp[i][j] != -1)
      return dp[i][j];

      int up = grid[i][j] + f(i - 1, j , grid, dp);
      int left = grid[i][j] + f(i, j -1 , grid, dp);
      
      return dp[i][j] = min(left , up);
  }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));  
        return f(n-1, m-1, grid, dp);
    }
};
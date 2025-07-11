class Solution {
  public:  //same row for alice and bob just diff col
  // recursion + memoization
  int f(int i , int j1, int j2, int r, int c, vector<vector<int>> &grid,  vector<vector<vector<int>>> &dp)
  {
      if(j1 < 0 || j2 < 0 || j1 >= c || j2 >= c) // out of bounds base case
      return -1e8;
      
      if(i == r-1) // reached the last row - destination
      {
          // if they reached same cell count it once
          if(j1 == j2)
          return grid[i][j1]; 
          
          else // reached diff cells 
          return grid[i][j1] + grid[i][j2];
          
         
      }
      
      if(dp[i][j1][j2] != -1)
      return dp[i][j1][j2];
      
      
    // Explore all paths of Alice and Bob simultaneously
    // left diag , down , right diag
    int maxi = 0;
    for(int dj1 = -1; dj1 <= +1; dj1++ )
    {
        for(int dj2 = -1; dj2 <= +1; dj2++)
        {
            int value = 0;
            
            // if their path involves a common cell consider it once
            if(j1 == j2)
            value = grid[i][j1];
            
            else
            value = grid[i][j1] + grid[i][j2];
            
            // recursive call
            //       next row, alice , bob combinations
            value += f(i +1, j1 + dj1 , j2 + dj2, r, c, grid,  dp);
            
            maxi = max(maxi, value);
        }
    
    }
    return dp[i][j1][j2] = maxi;
  }
  
  
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m , vector<int> (m , -1)));// 3 d vector declaration
        
        return f(0,0, m-1, n, m, grid, dp );
    }






    #include <bits/stdc++.h> 
int maximumChocolates(int n, int m, vector<vector<int>> &grid) {


    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1e8))); // invalid-path sentinel
    // base cases 
    // for i  =n -1 , j1 and j2 varies
    for(int j1 = 0; j1 < m; j1++) {
        for(int j2 = 0; j2 < m; j2++) {
            if (grid[n-1][j1] == -1 || grid[n-1][j2] == -1) continue; // obstacle check
            if(j1 == j2) // if they reach same cell - count only once
            {
                dp[n-1][j1][j2] = grid[n-1][j1];
            }
            else
                dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2]; // else
        }
    }

    for(int i = n-2; i >= 0; i--)
    {
        for(int j1 = 0; j1 < m; j1++)
        {
            for(int j2 = 0; j2 < m; j2++)
            {
                if (grid[i][j1] == -1 || grid[i][j2] == -1) { // obstacle check
                    dp[i][j1][j2] = -1e8;
                    continue;
                }

                int maxi = -1e8;
// Exploring all paths alice & bob can go together
// right diag, down , left diag 
                for(int dj1 = -1; dj1 <= +1; dj1++)
                {
                    for(int dj2 = -1; dj2 <= +1; dj2++)
                    {
                        int value = 0;

                        // if both have a cell in common count it once
                        if(j1 == j2)
                            value = grid[i][j1];
                        else 
                            value = grid[i][j1] + grid[i][j2];
    // to avoid out of bounds error

                        int nj1 = j1 + dj1, nj2 = j2 + dj2;
                        if(nj1 >= 0 && nj1 < m && nj2 >= 0 && nj2 < m && dp[i+1][nj1][nj2] != -1e8)
                            value += dp[i+1][nj1][nj2];
                        else 
                            value += -1e8;

                        maxi = max(maxi, value);
                    }
                }

                dp[i][j1][j2] = maxi;
            }

        }
    }
    return max(0, dp[0][0][m-1]);

    }
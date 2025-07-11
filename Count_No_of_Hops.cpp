class Solution {
  public:
  
  int count(int n, vector<int> &dp)
  {//! Top down approach 
      if(n <= 1)
      return 1;
      
      if(n == 2 )
        return 2;
        
        if(dp[n] != -1)
        return dp[n];
        
        //store the result before returning 
        return dp[n] = count(n-1, dp) + count(n-2, dp) + count(n-3, dp);
  }
    // Function to count the number of ways in which frog can reach the top.
    int countWays(int N) {

        vector<int>dp(N+1, -1);

        return count(N , dp);
    }
};

class Solution {
  public:
    // Function to count the number of ways in which frog can reach the top.
    int countWays(int n) {

        // your code here
        // Bottom up approach 
        
        vector<int>dp(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i = 3; i <= n ; i++)
        {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
            
        }
        return dp[n];
    }
};



class Solution {
  public:
    // Function to count the number of ways in which frog can reach the top.
    int countWays(int n) {

        // your code here
        // Space optimization
        if(n == 1 || n == 2)
        return n;
        
        int prev2 = 1, prev1 = 1, prev = 2, curr;
        
        for(int i = 3; i <= n ; i++)
        {
            curr = prev + prev1 + prev2;
            prev2 = prev1; 
            prev1 = prev;
            prev = curr;
        }
        return curr;
    }
};

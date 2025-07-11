  class Solution {
  // This is a simple implementation of the Fibonacci sequence using recursion and memoization.
  //! Top Down Approach 
  public:
  
  int fibo(int n, vector<int>&dp)
  { // Tc = o(N)
    // SC = o(N)
      
        // base case
        if(n <= 1)
        return n;
        
        // if result is already calculated return it 
        if(dp[n] != -1)
        return dp[n];
        
        // storing the result before return ing
        return dp[n] = fibo(n-1, dp) + fibo(n-2, dp);  
        
  }
  
    int fib(int n) {
        // dynamic programming
        vector<int>dp(n + 1, -1);
        return fibo(n, dp);
    }
};
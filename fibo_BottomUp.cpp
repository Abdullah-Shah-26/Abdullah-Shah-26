//   class Solution {
//   // This is a simple implementation of the Fibonacci sequence using recursion and memoization.
//   public:
  
//   int fibo(int n, vector<int>&dp)
//   { // Tc = o(N)
//     // SC = o(N)
      
//         // base case
//         if(n <= 1)
//         return n;
        
//         // if result is already calculated return it 
//         if(dp[n] != -1)
//         return dp[n];
        
//         // storing the result before return ing
//         return dp[n] = fibo(n-1, dp) + fibo(n-2, dp);  
        
//   }
  //! BOTTOM UP APPROACH
    int fib(int n) {
        // edge 
        if(n <= 1)
        return n;

        // dynamic programming
        vector<int>dp(n + 1, -1);
        
        dp[0] = 0;
        dp[1] = 1; // cannot accces if n = 0
        
        for(int i = 2; i <= n ; i++)
        dp[i] = dp[i-1] + dp[i -2];

        return dp[n];
    }
};
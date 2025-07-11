class Solution {
  public:
  int f(int i , int j , string &s1, string &s2, vector<vector<int>> &dp)
  {
      if(i < 0)// s1 got exhausted
      return j + 1; 
      
      if(j < 0)// s2 got exhausted
      return i + 1; 
      
      if(dp[i][j] != -1)
      return dp[i][j];
      
      if(s1[i] == s2[j])// char match // dont do anything no steps req
      return dp[i][j] = 0 + f(i -1, j -1, s1, s2, dp);
        // min of delete               // or insert         // or replace
      return dp[i][j] = 1 + min(f(i-1, j, s1, s2, dp), min(f(i, j-1, s1, s2, dp), f(i-1, j-1, s1, s2, dp)));
      
      
  }
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>>dp(n, vector<int>(m , -1));
        return f(n-1, m-1, s1, s2, dp);
    }


    int editDistance(string s1, string s2)
{
    //! Bottom UP approach
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>>dp(n +1, vector<int>(m + 1, 0)); // 1 based idx to avoid dealing with -ve base case

    for(int j = 0; j <= m ; j++)
    dp[0][j] = j ;
    for(int i = 0; i <= n; i++)
    dp[i][0] = i;

    for(int i = 1; i<= n ;i++)
    {
        for(int j = 1; j <= m; j++)
        {
            // if char match dont do anything
            if(s1[i-1] == s2[j-1])
            dp[i][j] = 0 + dp[i-1][j-1];
            else // dont match then no of ops = min deletion , insertion , replacing
            dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));

        }
    }
    return dp[n][m];
}


class Solution {
public:
    int minDistance(string s1, string s2) {

    //! Space Optimization
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>>dp(n +1, vector<int>(m + 1, 0)); // 1 based idx to avoid dealing with -ve base case

    // for(int j = 0; j <= m ; j++)
    // dp[0][j] = j ;
    // for(int i = 0; i <= n; i++)
    // dp[i][0] = i;

    vector<int>prev(m +1, 0), curr(m + 1,0 );
   
   for(int j = 0; j <=m ;j++)
   prev[j] = j;

    for(int i = 1; i<= n ;i++)
    {  curr[0] =i;
        for(int j = 1; j <= m; j++)
        {
          
             // if char match dont do anything
            if(s1[i-1] == s2[j-1])
            curr[j] = 0 + prev[j-1];
            else // dont match then no of ops = min deletion , insertion , replacing
            curr[j] = 1 + min(prev[j], min(curr[j-1], prev[j-1]));

        }
    prev = curr;
    }
    return prev[m];

    }
};
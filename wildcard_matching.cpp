class Solution {
public:
 
bool f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    // if both of them exhausted 
    if(i < 0 && j < 0)
    return 1;
    // if s1 exhausted but not s2 means they didnt match    
    if(i < 0 && j >= 0 )
    return 0;
    
    if(j < 0 && i >= 0)
    {
    // s2 exhausted but not s1 them to match s1 must have all stars
    for(int ii = 0; ii <= i; ii++)
    {
        if(s1[ii] != '*')
        return 0;
    }
        return 1;
    }
    if(dp[i][j] != -1)
    return dp[i][j];
    
 
    
    // if s1 and s2 matches or if s1 has ? it can match with any char of s2
    if(s1[i] == s2[j] || s1[i] == '?')
    return dp[i][j] = f(i-1, j-1, s1, s2, dp);
    
    // if char of s1 is a * we have to choices take it as null or take is as equal to char of s2
    if(s1[i] == '*')
    return dp[i][j] = f(i-1, j, s1, s2, dp) | f(i, j-1, s1, s2, dp);
    
    
    return dp[i][j] = 0; // the char is not * / ?
    
}

     bool isMatch(string text, string pattern) {
    int n = pattern.size();
    int m = text.size();
    
    vector<vector<int>>dp(n, vector<int>(m , -1));
    return f(n-1, m-1, pattern, text, dp);
    }
};

int Solution::isMatch(const string text, const string pattern) {
   // bottom up approach
   
   int n = pattern.size();
   int m = text.size();
   
   vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
   // base cases
   dp[0][0] = true;
   // 
   for(int j = 1; j <= m ; j++)
   {
       dp[0][j] = false;
   }
   for(int i = 1; i<= n; i++)
   {
       bool flag = true;
       for(int ii = 1; ii <= i; ii++)
       {
           if(pattern[ii -1 ] != '*')
           {
               flag = false;
               break;
           }
       }
       dp[i][0] = flag;
   }
   
   for(int i =1; i <=n; i++)
   {
       for(int j =1; j <= m ;j++)
       {
           if(pattern[i-1] == text[j-1] || pattern[i-1] == '?')
           dp[i][j] = dp[i-1][j-1];
           else if(pattern[i-1] == '*') // 2 choices // * as null // * treated as same char of text
           dp[i][j] = dp[i-1][j] || dp[i][j-1];
           else// char is neither star or questin mark
           dp[i][j] = false;
       }
   }
   
   return dp[n][m];
    
}






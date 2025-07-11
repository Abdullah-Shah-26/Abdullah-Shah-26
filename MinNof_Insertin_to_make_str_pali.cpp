class Solution {
public:
//! and Min no of deletions too to make a stirng palindrome
int LCS(string s, string t)
{
    int n = s.size();
    int m = t.size();

    vector<int>prev(m + 1 , 0);
    vector<int>curr(m + 1, 0);

    // Space Optmized 
    for(int i = 1; i <= n ; i++)
    {
        for(int j =1 ; j <=m ; j++)
        {
            // match found
            if(s[i-1] == t[j-1])
            curr[j] = 1 + prev[j-1];

            else 
            curr[j] = max(prev[j], curr[j-1]);
        }
        prev = curr;
    }
    return prev[m];
}

int LPS(string s)
{
    // to find lps we  can just common bw given string and its reversed version
    string t =s ;
    reverse(s.begin(), s.end());
    return LCS(s, t);
}
    int minInsertions(string s) {
      // the min no of insertions are length of given string - length of longest palindromic subsequence  
      return s.size() - LPS(s);
    }
};
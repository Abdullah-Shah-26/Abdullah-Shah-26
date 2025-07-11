class Solution {

  public:
  
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
// we can just use LCS 
// total ops = len of str 1 + 2 - lcs of (s1, and s2)
    int minOperations(string &s1, string &s2) {
        // Your code goes here
        return s1.size() + s2.size() - 2 * LCS(s1, s2);
    }
};
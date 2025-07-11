class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
       vector<vector<int>>dp(m, vector<int>(n , 0));     // bottom up
     dp[0][0] = 1;
     for(int i = 0; i < obstacleGrid.size(); i++)
     {
        for(int j = 0; j < obstacleGrid[i].size() ; j++)
        {
            if(obstacleGrid[i][j] == 1)
            dp[i][j] = 0; // since obstacle is present

            // reached destination 
            else if(i == 0 && j == 0)
            {
                dp[i][j] = 1;

            }
            else
            {
                int up = 0;
                int left = 0;

                if( i > 0)
                up = dp[i-1][j];
                if(j > 0)
                left = dp[i][j-1];

            dp[i][j] = up + left;
            }
        }
     }   
    return dp[m-1][n-1];
    }
};   

// space optimization

vector<int>prev(m, 0);

for(int i = 0; i < m ; i++)
{
    vector<int>curr(n, 0);
    for(int j = 0; j < n; j++)
    {
        // if obstacle is present
        if(mat[i][j] == -1)
        curr[j] = 0;

        else if ( i == 0 && j == 0)
        curr[j] = 1; // reach destination point

        else{
            int up = 0;
            int left = 0;

            if(i > 0)
            up = prev[j];

            if(j > 0)
            left = curr[j -1];

            curr[j] = up + left;
        }
}
prev = curr;
}
return prev[m-1];
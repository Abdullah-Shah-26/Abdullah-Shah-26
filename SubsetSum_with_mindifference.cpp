class Solution {

  public:
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        int totsum = 0;
        for(int i =0 ; i<n; i++)
        totsum += arr[i];
        
        int k = totsum;
        
        vector<vector<bool>>dp(n , vector<bool>(k +1, 0));
        
        // there is always a way to pick tar = 0, pick nothing
        for(int i = 0; i < n; i++)
        dp[i][0] = true;
        
        if(arr[0] <= k)
        dp[0][arr[0]] = true;
        
        for(int idx = 1; idx < n; idx++)
        {
            for(int target = 1; target <=k ; target++)
            {
                bool nottake = dp[idx-1][target];
                bool take = false;
                
                if(arr[idx] <= target)
                take = dp[idx -1][target - arr[idx]];
                
                dp[idx][target] = take | nottake;
            }
        }
        
        
        int mini = 1e9;
      // instead of making another subarray and calculatingits sum 
      // we are finding it from totalsum 
        for(int s1 = 0; s1 <= totsum/2; s1++)
        {
            if(dp[n-1][s1] == true){
                mini = min(mini, abs((totsum - s1)-s1));
            }
        }
        return mini;
    }
};

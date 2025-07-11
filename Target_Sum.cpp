class Solution {
public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        // dp[i][t] = # of ways to get sum t using first i elements (arr[0..i-1])
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        
        // Base case: with 0 elements, there's exactly 1 way to make sum=0 (pick nothing)
        dp[0][0] = 1;
        
        // Fill the table
        for(int i = 1; i <= n; ++i) {
            int val = arr[i-1];
            for(int t = 0; t <= target; ++t) {
                // 1) exclude current element
                dp[i][t] = dp[i-1][t];
                
                // 2) include current element (if it doesn't overshoot)
                if (t >= val)
                    dp[i][t] += dp[i-1][t - val];
                
                // (optional) if the problem wants results mod 1e9+7:
                // dp[i][t] %= 1000000007;
            }
        }
        
        // The answer: using all n elements to make exactly 'target'
        return dp[n][target];
    }
};


//!--------------------------------------------------------------------------\
class Solution {
public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        // dp[i][t] = # of ways to get sum t using first i elements (arr[0..i-1])
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        
        // Base case: with 0 elements, there's exactly 1 way to make sum=0 (pick nothing)
        dp[0][0] = 1;
        
        // Fill the table
        for(int i = 1; i <= n; ++i) {
            int val = arr[i-1];
            for(int t = 0; t <= target; ++t) {
                // 1) exclude current element
                dp[i][t] = dp[i-1][t];
                
                // 2) include current element (if it doesn't overshoot)
                if (t >= val)
                    dp[i][t] += dp[i-1][t - val];
                
                // (optional) if the problem wants results mod 1e9+7:
                // dp[i][t] %= 1000000007;
            }
        }
        
        // The answer: using all n elements to make exactly 'target'
        return dp[n][target];
    }
};



class Solution {
public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> dp(target+1, 0);
        dp[0] = 1;  // one way to make sum 0: pick nothing

        for (int i = 0; i < n; ++i) {
            int val = arr[i];
            // go backwards so each arr[i] is only counted once
            for (int t = target; t >= val; --t) {
                dp[t] += dp[t - val];
                // if you need mod 1e9+7: dp[t] %= 1000000007;
            }
        }

        return dp[target];
    }
};

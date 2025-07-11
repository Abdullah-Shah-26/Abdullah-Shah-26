class Solution {
public:// Top down 
    int Robber(int index, vector<int>& nums, vector<int> &dp)
    {
        if(index == 0)
        return nums[0];

        if(index == 1)
        return max(nums[0], nums[1]);

    // return already stored result 
        if(dp[index] != -1)
        return dp[index];

                // Robbed                               // Not Robbed
        return dp[index] =max(nums[index] + Robber(index-2, nums, dp), Robber(index -1, nums, dp));
        // store the result before returning
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n + 1, -1);
        return Robber(n-1, nums, dp);
    }
};




    int rob(vector<int>& nums) {
        // BOTTOM UP approach
        int n = nums.size();

        if(n == 1)
        return nums[0];

        if(n == 2)
        return max(nums[0], nums[1]);

        vector<int>dp(n + 1, -1);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]); // if n = 1 this wont be accessible 


        
        for(int i = 2; i <n ;i++)
        {
            dp[i] = max(nums[i] + dp[i -2], dp[i-1]);
        }
        return dp[n-1];
    }
};



 int rob(vector<int>& nums) {
        // SPACE OPTIMIZATION
        int n = nums.size();

        if(n == 1)
        return nums[0];

        if(n == 2)
        return max(nums[0], nums[1]);

        vector<int>dp(n + 1, -1);
        int curr, prev = max(nums[0], nums[1]) , prev2 = nums[0] ;


        
        for(int i = 2; i <n ;i++)
        {
            curr = max(nums[i] + prev2, prev);
            prev2 =  prev;
            prev = curr;
        }
        return curr;
    }
};

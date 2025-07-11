class Solution {
public:
bool subsetsumtok(int n , int k , vector<int> &arr)
{   // Space optimized approach
    vector<bool>prev(k +1,0), curr(k + 1,0);

    prev[0] = curr[0] = true;
        if (arr[0] <= k) // Only set this if the first element is within bounds means target can be formed using first element
            prev[arr[0]] = true;

    for(int idx =1; idx < n; idx ++)
    {
        for(int target =1; target <=k ; target++)
        {
            bool nottake = prev[target];
            bool take = false;

            if(arr[idx] <= target)
            take = prev[target- arr[idx]];

            curr[target] = take || nottake;
        }
        prev = curr;
    }
    return prev[k];
}



    bool canPartition(vector<int>& nums) {
        int totalsum = 0;

        for(int i = 0; i < nums.size(); i++)
        totalsum += nums[i];

    if(totalsum % 2 != 0)
        return 0; // cannot divide odd sum equally among 2 subsets

        int target = totalsum /2;
        return subsetsumtok(nums.size(), target , nums );
    
    }
};
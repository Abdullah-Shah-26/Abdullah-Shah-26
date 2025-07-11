class Solution {
public:
// SC = O(n) // extra 2 arrays
    int Robbery(vector<int> &nums)
    {
        int n = nums.size();
    if(n == 1 )
    return nums[0];

    if(n == 2)
    return max(nums[0], nums[1]);

    int curr, prev =  max(nums[0], nums[1]), prev2 = nums[0];

    for(int i = 2; i <n ; i++)
    {
        curr = max(nums[i] + prev2, prev);
        prev2 = prev; 
        prev = curr;
    }
    return curr;
    }


    int rob(vector<int>& nums) {

    int n = nums.size();
    vector<int>arr1(n-1);
    vector<int>arr2(n-1);
    // Edge case
    if(n == 1 )
    return nums[0];

    if(n == 2)
    return max(nums[0], nums[1]);

// by taking 2 arrays we are avoiding condition where we rob 
// from both 0th and last index
    for(int i = 0; i < n-1; i++)
    {
        arr1[i] = nums[i];
    } 
    for(int i = 1; i< n; i++)
    {
        arr2[i-1] = nums[i];
    }
    // max robbery from arr1 and arr2
    int curr1 = Robbery(arr1);
    int curr2 = Robbery(arr2);

    return max(curr1, curr2);
    }
};


//!-----------------------------------------------------------------------------------------


class Solution {
public:
    int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int>arr1(n-1);
    vector<int>arr2(n-1);
    // Edge case
    if(n == 1 )
    return nums[0];

    if(n == 2)
    return max(nums[0], nums[1]);

// by taking 2 arrays we are avoiding condition where we rob 
// from both 0th and last index
   
//! WITHOUT USING EXTRA ARRAYS
    int curr1, prev =  max(nums[0], nums[1]), prev2 = nums[0];
    curr1 = prev; // to handle edge case of just 3 size arr 
//   EXCLUDING LAST INDEX
    for(int i = 2; i < n-1 ; i++)
    {
        curr1 = max(nums[i] + prev2, prev);
        prev2 = prev; 
        prev = curr1;
    }
//   EXCLUDING FIRST INDEX 
    int curr2; // shift everything by 1
    prev =  max(nums[1], nums[2]), prev2 = nums[1];
    curr2 = prev;
    for(int i = 3; i <n ; i++)
    {
        curr2 = max(nums[i] + prev2, prev);
        prev2 = prev; 
        prev = curr2;
    }
    return max(curr1, curr2);
    }
};
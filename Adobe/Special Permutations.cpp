class Solution {
public:
    int mod = 1e9+7;
    int solve(int mask, int prev, vector<int> &nums, int n, vector<vector<int>> &dp)
    {
        if(mask == (1<<n)-1)
            return 1;
        int ans = 0;
        if(dp[mask][prev+1] != -1)
            return dp[mask][prev+1];
        if(prev == -1)
        {
            for(int i = 0 ; i < n ; i++)
            {
                ans = (ans + solve(mask | (1 << i), i, nums, n, dp)) % mod;
            }
        }
        else
        {
            for(int i = 0 ; i < n ; i++)
            {
                if(!(mask & (1 << i)))
                {
                    if(nums[prev]%nums[i] == 0 || nums[i]%nums[prev] == 0)
                    {
                        ans = (ans + solve(mask | (1 << i), i, nums, n, dp))%mod;
                    }
                }

            }
        }
        return dp[mask][prev+1] = ans%mod;
    }
    int specialPerm(vector<int>& nums) {
        vector<vector<int>> dp(1<<nums.size(), vector<int> (nums.size()+1, -1));
        return solve(0, -1, nums, nums.size(), dp);
    }
};

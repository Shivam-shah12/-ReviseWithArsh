class Solution {
public:
    vector<vector<int>>ans;
    void solve(int ind,vector<int>&nums,vector<int>count,int k,int target)
    {
        // base case
        if(ind>=nums.size())
        {
           if(count.size()==k && target==0)
            { ans.push_back(count);}
             return;
        }
        if(nums[ind]<=target) 
         {   count.push_back(nums[ind]);
            solve(ind+1,nums,count,k,target-nums[ind]);
            count.pop_back();
        }
        solve(ind+1,nums,count,k,target);
        return;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        // in these question we used backtracking or recursion
        vector<int>nums;
        vector<int>count;
        for(int i=1;i<=9;i++)nums.push_back(i);
        // call the recursive function
        solve(0,nums,count,k,n);
        return ans;
    }
};
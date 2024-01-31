class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int prod=0;
        cout<<sum<<endl;
        for(int i=0;i<nums.size();i++)
        {
            prod+=i*nums[i];
        }
        int n=nums.size();
        int ans=prod;
        for(int i=1;i<nums.size();i++)
        {
            int curr=prod+sum-nums[n-i]*n;
            ans=max(ans,curr);
            prod=curr;
        }
        return ans;
       
    }
};

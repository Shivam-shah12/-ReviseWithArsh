class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // changed num in 1 or 0 format
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]&1)
            nums[i]=1;
            else
            nums[i]=0;
        }
        // [ 1 1 0 1 1]
        map<int,int>mp;
        mp[0]=1;
        int j=0;
        int sum=0;
        int ans=0;
        int n=nums.size();
        while(j<n)
        {
           sum+=nums[j];
           mp[sum]++;
          
           if(mp.find(sum-k)!=mp.end())
           {
              cout<<mp[sum-k]<<endl;
              ans+=mp[sum-k];
           }
           j++;
        }
        return ans;
    }
};

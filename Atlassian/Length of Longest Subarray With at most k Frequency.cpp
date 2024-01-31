class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int,int>mp;
        int i=0;
        int j=0;
        set<int>st;
        for(auto val:nums)
            st.insert(val);
        int max_len=st.size()*k;
        int cnt=0;
        int n=nums.size();
        while(j<n)
        {
            mp[nums[j]]++;
            int curr=nums[j];
            while(j-i>=max_len || mp[curr]>k)
            {
                mp[nums[i]]--;
                i++;
            }
            cnt=max(cnt,j-i+1);
            j++;
        }
        return cnt;
    }
};

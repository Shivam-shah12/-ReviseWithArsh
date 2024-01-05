class Solution {
public:
 
    int solve(vector<int>& nums,int k,int p)
    {
        int i=0;int j=0;
        int count=0;
        set<vector<int>>st;
        vector<int>v;
        int n=nums.size();
        while(i<n)
        {
            if(j<n && nums[j]%p==0)
            count++;
            if(count>k || j>=n)
            {
              i++;
              j=i;
              count=0;
              continue;
            }
            for(int k=i;k<=j;k++)
            {
              v.push_back(nums[k]);
            }
        
            st.insert(v);
            v.clear();
        
            j++;
        }
       
        return st.size();
    }
    int countDistinct(vector<int>& nums, int k, int p) {
       // Better Approach 
        return solve(nums,k,p);
        
        
    }
};

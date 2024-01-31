class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<pair<int,int>>st;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
          for(int j=i+1;j<nums.size();j++)
          {
              if(nums[j]-nums[i]>k)
              break;
              else if(abs(nums[j]-nums[i])==k)
              {
                  st.insert({nums[j],nums[i]});
              }
          }
        }
        return st.size();
    }
};

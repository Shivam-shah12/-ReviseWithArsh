class Solution {
public:
    bool issort(vector<int>curr)
    {
          for(int i=1;i<curr.size();i++)
          {
             if(curr[i]>curr[i-1])
                 continue;
              else
                  return false;
          }
        return true;
    }
  
    int incremovableSubarrayCount(vector<int>& nums) {
        int cnt=0;
        int len=nums.size();
        vector<vector<int>>allrem;
       for( int i=0; i<len; i++ ){
        for( int j=i; j<len; j++ ){  
            vector<int>rem;// Now A[i..j] is the subarray
            for(int s=0;s<len;s++)
            {
              if(s>=i && s<=j)
              {}
                else
                {
                    rem.push_back(nums[s]);
                }
            }
            allrem.push_back(rem);
        }
    }
      for(auto val:allrem)
      {
          if(issort(val))
              cnt++;
      }
        return cnt;
    }
};

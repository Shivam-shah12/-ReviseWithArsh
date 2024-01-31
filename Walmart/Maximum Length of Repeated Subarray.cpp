class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        // we create a 2-d array which store upto ith index , how much character common between them
        vector<vector<int>>dp(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                if(nums1[i]!=nums2[j])
                continue;
                else if(i-1>=0 && j-1>=0)
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                   dp[i][j]=1;
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
        
    }
};

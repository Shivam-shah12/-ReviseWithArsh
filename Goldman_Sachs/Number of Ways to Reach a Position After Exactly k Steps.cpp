class Solution {
public:
    int mod=1e9+7;
    long long solve(int start,int& end,int k,vector<vector<long long>>&dp)
    {
        if(k==0 && start==end)
        return 1;
        if(k==0)
        return 0;
        if(dp[start+1000][k]!=-1)
        return dp[start+1000][k];
        // we take two ways
        long long ans1=solve(start+1,end,k-1,dp);
        long long ans2=solve(start-1,end,k-1,dp);
        return dp[start+1000][k]=(ans1+ans2)%mod;

    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<long long>>dp(3001,vector<long long>(1001,-1));
        return (int)solve(startPos,endPos,k,dp)%mod;
        
    }
};

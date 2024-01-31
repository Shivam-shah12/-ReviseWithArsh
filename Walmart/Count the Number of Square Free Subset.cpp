class Solution {
public:
    int gcd(int a,int b){
        return b==0 ?  a :  gcd(b,a%b);
    }
    int primes[10]={2,3,5,7,11,13,17,19,23,29};
    int squares[4]={4,9,16,25};

    int mod=1e9+7;
    
    bool poss(int x,vector<int>&vis){
        for(int i=0;i<10;i++){
            if(x%primes[i]==0 && vis[i]>0)return false;
        }
        for(int i=0;i<4;i++){
            if(x%squares[i]==0)return false;
        }
        return true;
    }

    int solve(int n,vector<int>& nums,vector<int>&vis,vector<vector<int>>&dp){
        if(n==0)return 1;
        int ct=0;
        for(int i=0;i<10;i++){
            if(vis[i]==1){
                ct+=(1<<i);
            }
        }
        
        if(dp[n][ct]!=-1)return dp[n][ct];

        int ans=solve(n-1,nums,vis,dp);
        
        if(poss(nums[n-1],vis)){
            for(int i=0;i<10;i++){
                if(nums[n-1]%primes[i]==0)vis[i]=1;
            }
            long long x=((long long)ans%mod + (solve(n-1,nums,vis,dp))%mod)%mod;
            ans=x;
            for(int i=0;i<10;i++){
                if(nums[n-1]%primes[i]==0)vis[i]=0;
            }
        }
        
        return dp[n][ct]=ans;
    }

    int squareFreeSubsets(vector<int>& nums) {
        int n=nums.size();
        vector<int>vis(11,0);
        vector<vector<int>>dp(n+1,vector<int>(1<<10,-1));
        int ans=solve(n,nums,vis,dp);
        if(ans-1==-1)return 1000000006;
        return ans-1;
    }
};
/*
*/

class Solution {
public:
int mod = 1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>dp(n+1,0);
        dp[1] = 1;

        long long users =0;
        for(int i=2;i<=n;i++){
            if(i-delay>=0){
                users = users + dp[i-delay]; //spread new user
            }if(i-forget>=0){
                users = users - dp[i-forget]; //remove forgot user
            }
            dp[i] = users%mod;
        }
        long long ans =0;
        for(int i=n-forget+1;i<=n;i++){
            ans = (ans+dp[i])%mod;
        }
        return ans; 
    }
};

class Solution {
public:

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b){
            if(a[0]==b[0])return a[1]>b[1];
            return a[0]<b[0];
        });
        vector<int> another;
        for(auto x : envelopes){
            another.push_back(x[1]);
        }
        vector<int> dp(another.size()+1, INT_MAX);
        dp[0]=INT_MIN;
        for(int i=0;i<another.size();i++){
            int l = upper_bound(dp.begin(), dp.end(), another[i]) - dp.begin();
            if(dp[l-1]<another[i] and another[i]<dp[l]){
                dp[l]=another[i];
            }
        }
        int ans=0;
        for(int i=1;i<=another.size();i++){
            if(dp[i]!=INT_MAX){
                ans=i;
            }
        }
        return ans;
    }
};

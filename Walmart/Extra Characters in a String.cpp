class Solution {
public:
    int solve(int index,string& s,unordered_map<string,bool>&mp,vector<int>& dp)
    {
        if(index>=s.size())
            return 0;
        
        if(dp[index]!=-1)
            return dp[index];
        string curr="";
        int res=s.size();
        for(int i=index;i<s.length();i++)
        {
            curr.push_back(s[i]);
            int extraCount=curr.size();
            if(mp[curr])
                extraCount=0;
            
            extraCount+=solve(i+1,s,mp,dp);
            res=min(res,extraCount);
        }
        return dp[index]=res;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int>dp(s.size(),-1);
        unordered_map<string,bool>mp;
        for(auto val:dictionary)
            mp[val]=true;
        
        return solve(0,s,mp,dp);
        
    }
};

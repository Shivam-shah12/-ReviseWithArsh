class Solution {
public:
    int dp[301];
    bool solve(int i,string s,set<string>& st)
    {
        if(i==s.size())
        return true;
        if(dp[i]!=-1)
        return dp[i];
        string temp;

        for(int j=i;j<s.size();j++)
        {
            temp+=s[j];
            if(st.find(temp)!=st.end())
            {
                if(solve(j+1,s,st))return dp[i]=1;
            }
        }
        return dp[i]=0;
    }
 
    bool wordBreak(string s, vector<string>& word) {
        set<string>st;
        memset(dp,-1, sizeof(dp));
        for(auto val:word)
        {
            st.insert(val);
        }
        return solve(0,s,st);
        
    }
};

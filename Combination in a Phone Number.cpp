class Solution {
public:
    void solve(int ind,string digits,vector<string>& ans,map<char,vector<int>>mp,string str)
    {
        if(ind>=digits.size())
        {
           ans.push_back(str);
           return;
        }

        for(auto val:mp[digits[ind]])
        {
            str+=val;
            solve(ind+1,digits,ans,mp,str);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
        return {};
        map<char,vector<int>>mp;
        char ch=96;
        for(int i=2;i<=9;i++)
        {
           if(i==7 || i==9)
           {
            mp[i+'0']={ch+1,ch+2,ch+3,ch+4};
            ch+=4;
            continue;
           }
           mp[i+'0']={ch+1,ch+2,ch+3};
           ch+=3;
        }
        // for(auto val:mp)
        // cout<<val.first<<"-->"<<val.second[0]<<" "<<val.second[1]<<" "<<val.second[2]<<endl;

        vector<string>ans;
        string str="";
        solve(0,digits,ans,mp,str);
        return ans;
    }
};
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>Subsequence;
        map<string,int>mp;
        int left=0;
        for(int right=0;right<s.length();right++)
        {
            if(right-left+1==10)
            {
               string temp=s.substr(left,right-left+1);
               mp[temp]++;
            }
            while(right-left+1>=10)
            {
                left++;
            }
        }
        for(auto val:mp)
        {
            if(val.second>1 && val.first.length()==10)
            Subsequence.push_back(val.first);
            cout<<val.first<<endl;
        }
        return Subsequence;
        
    }
};

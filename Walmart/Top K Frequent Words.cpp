class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        for(auto val:words)
        {
            mp[val]++;
        }
        vector<pair<string,int>>vec(mp.begin(),mp.end());
        sort(vec.begin(),vec.end(),[] (const auto& a,const auto&b){
            if(a.second==b.second)
            return a.first<b.first;
            return a.second>b.second;
        });
        // reverse(vec.begin(),vec.end());
        vector<string>ans;
        for(auto val:vec)
        {
            if(k==0)
            break;
            ans.push_back(val.first);
            k--;
        
        }
        
        return ans;
        
    }
};

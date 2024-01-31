class Solution {
public:
    string frequencySort(string s) {
       map<char,int>mp;
        for(auto val:s)
        mp[val]++;
        vector<std::pair<char, int>> vec(mp.begin(), mp.end());

    // Sort the vector based on the second element of pairs (the values)
    sort(vec.begin(), vec.end(), [](const auto &a, const auto &b) {
        return a.second < b.second;
    }); 
        string ans="";    
        for(auto val:vec)
        {
            char ch=val.first;
            int freq=val.second;
            while(freq--)
            ans+=ch;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

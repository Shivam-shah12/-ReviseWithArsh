class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        
        vector<int>a_freq;
        vector<int>b_freq;
        int pos=s.find(a);
        while(pos!=string::npos)
        {
            a_freq.push_back(pos);
            pos=s.find(a,pos+1);
        }
        pos=s.find(b);
        while(pos!=string::npos)
        {
            b_freq.push_back(pos);
            pos=s.find(b,pos+1);
        }
        set<int>st;
        vector<int>v;
    
        for(int i=0;i<a_freq.size();i++)
        {
            for(int j=0;j<b_freq.size();j++)
            {
                if(abs(a_freq[i]-b_freq[j])<=k)
                    {st.insert(a_freq[i]);
                    break;}
            }
        }
        
       
        
        for(auto val:st)
        {
            v.push_back(val);
        }
        // reverse(v.begin(),v.end());
        return v;
        
    }
};

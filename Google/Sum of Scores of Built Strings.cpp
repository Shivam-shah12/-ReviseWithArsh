class Solution {
public:
    void f(string &s,vector<int> &z){
        int l = 0,r = 0;
        for(int i=1;i<s.length();i++){
            if(i <= r) z[i] = min(r-i+1,(int)z[i-l]);
            
            while(s[z[i]] == s[i + z[i]]) 
                z[i]++;
            
            if(i+z[i]-1 > r){
                l = i;
                r = i + z[i] - 1;
            }
        }
    }
    long long sumScores(string s) {
        string str = s + s;
        vector<int> z(str.size());
        f(str,z);
        long long ans = accumulate(z.begin()+s.size(),z.end(),0LL);
        return ans;
    }
};

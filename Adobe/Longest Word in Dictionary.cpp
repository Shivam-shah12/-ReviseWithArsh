class Solution {
public:
    bool check(string &s , string &S){
        int j = 0;
        for(int i = 0; i<s.length(); i++){
            if(s[i]==S[j]){
                j++;
                if(j==S.length()) return true;
            }
        }
        return false;
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        for(string &S : dictionary){
            if(S.length()<ans.length() || (S.length()==ans.length()&&S>ans) ) continue;
            if(check(s,S)) ans = S;
        }
        return ans;
    }
};

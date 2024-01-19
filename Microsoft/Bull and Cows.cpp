class Solution {
public:
    string ansMaker(int bulls,int cows)
    {
        string ans="";
        ans=to_string(bulls)+"A"+to_string(cows)+"B";
        cout<<ans<<endl;
        return ans;
    }
    string getHint(string secret, string guess) {
        map<char,int>mp;
        for(int i=0;i<secret.size();i++)
        {
           mp[secret[i]]++;
        }

        int cows=0;
        int bulls=0;
        int n=secret.size();
        for(int i=0;i<n;i++)
        {
            if(secret[i]==guess[i])
            {
                bulls++;
                guess[i]=-1;
                mp[secret[i]]--;
            }
            if(mp[secret[i]]==0)
            {
               mp.erase(secret[i]);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(mp.find(guess[i])!=mp.end())
            {
                cows++;
                mp[guess[i]]--;
            }
            if(mp[guess[i]]==0)
            {
                mp.erase(guess[i]);
            }
        }
        
        
        

        return ansMaker(bulls,cows);
    }
};

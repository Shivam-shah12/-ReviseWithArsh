class Solution {
public:
    int conversion(string str)
    {
        int first=stoi(str.substr(0,2));
        int second=stoi(str.substr(2,2));
        return first*60+second;
    }

    bool check(vector<int>arr)
    {
       sort(arr.begin(),arr.end());
       // check any three consective values have difference less than 60 or not
       int i=0;
       int j=2;
       while(j<arr.size())
       {
           if(arr[j]-arr[i]<60)
           return true;
           j++;
           i++;
       }
       return false;
    }
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        
        unordered_map<string,vector<int>>mp;
        for(auto val:access_times)
        {
            int num=conversion(val[1]);
            mp[val[0]].push_back(num);
        }
        vector<string>ans;
        for(auto val:mp)
        {
            // jinki freq 3 se jyada ya barrabar hai , vohi kaam ke hai
            if(mp[val.first].size()>=3 && check(val.second))
            {
               ans.push_back(val.first);
            }
        }
      return ans;
    }
};
class Solution {
public:
 
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n=queries.size();
        int len=nums[0].size();
        // n is the length of queries
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int ki=queries[i][0];
            int trim_i=queries[i][1];
     priority_queue<std::pair<string, long long>, vector<std::pair<string, long long>>, greater<std::pair<string, long long>>> pq;
            map<int,int>mp;
            for(int j=0;j<nums.size();j++)
            {
                int pos=len-trim_i;
               string curr=nums[j].substr(pos,trim_i);
            //    cout<<curr<<endl;
               pq.push({curr,j});
            }
            ki-=1;
            
            while(ki)
            {
                pq.pop();
                ki--;
            }
            // cout<<pq.top()<<endl;
            ans.push_back(pq.top().second);
            
        }
        return ans;
    }
};
class Solution {
public:
int mod=1e9+7;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto val:nums)
        {
            pq.push(val);
        }
        long long prod=1;
        while(k--)
        {
           int curr=pq.top();
           curr+=1;
           pq.pop();
           pq.push(curr);
        }
        while(!pq.empty())
        {
            prod=(prod*pq.top())%mod;
            pq.pop();
        }
        
        return prod%mod;
        
    }
};

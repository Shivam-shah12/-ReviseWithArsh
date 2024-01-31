class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<int> dq;
        int n = nums.size();
        vector<int> sum(n,0);
        int res = INT_MIN;

        for(int i=0;i<n;i++){

            if(!dq.empty() && dq.front() < i-k) dq.pop_front();
            
            sum[i] = nums[i];
            sum[i] += dq.size() > 0? sum[dq.front()]: 0;
            cout<<sum[i]<<" ";
            res = max(res, sum[i]);

            while(!dq.empty() && sum[dq.back()] < sum[i]) dq.pop_back();
            
            if(sum[i] > 0) dq.push_back(i);
        }

        return res;
    }
};

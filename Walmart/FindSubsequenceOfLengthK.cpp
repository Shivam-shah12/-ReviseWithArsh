class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // min-heap we used bcoz , in min-heap --> minimum values should be deleted first or else we store k-element which are maximum as well in array
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
            if(pq.size()>k)pq.pop();
        }
        vector<int>ans;
        while(!pq.empty()){
            cout<<pq.top().first<<" ";
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)ans[i]=nums[ans[i]];
        return ans;
    }
};

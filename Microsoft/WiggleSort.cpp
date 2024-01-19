class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int low = 0;
        int high = nums.size()/2;
        vector<int> ans;
        while(low<nums.size()/2 && high<nums.size()){
            ans.push_back(nums[high++]);
            ans.push_back(nums[low++]);
        }
        while(high<nums.size()) ans.push_back(nums[high++]);
        nums = ans;
    }
};

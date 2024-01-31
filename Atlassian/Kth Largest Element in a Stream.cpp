class KthLargest {
public:
    
    priority_queue<int,vector<int>,greater<int>> pq;
    int size;
    KthLargest(int k, vector<int>& nums) {
        size=k;
         for(int i:nums){
            add(i);
        } 
    }
    int add(int val) {
        if(pq.size()<size){
            pq.push(val);
            return pq.top();
        }
        else if(pq.size()==size){
            pq.push(val);
            pq.pop();
            return pq.top();
        }
        return -1;

    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

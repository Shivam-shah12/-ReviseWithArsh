class Solution {
private:
    int M;
    int N;
    set<pair<int, int>> st;

public:
    Solution(int m, int n) {
        M = m;
        N = n;
    }
    
    vector<int> flip() {
        int x = rand() % M;
        int y = rand() % N;

        if(st.find({x, y}) != st.end()){
            return flip();
        }
        st.insert({x, y});
        return {x, y};
    }
    
    void reset() {
        st.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */

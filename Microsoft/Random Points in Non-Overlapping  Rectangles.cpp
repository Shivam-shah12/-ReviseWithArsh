class Solution {
public:
    int n;
    vector <int> ps;
    int area(vector<int> &r) {
        return ((r[2]-r[0]+1))*((r[3]-r[1]+1));
    }
    vector<vector<int>> rects;
    Solution(vector<vector<int>>& _rects) {
        rects = _rects;
        n = rects.size();
        ps.resize(n);
        ps[0] = area(rects[0]);
        for (int i = 1; i < n; i++) {
            ps[i] = ps[i-1] + area(rects[i]); 
        }
        for(auto val:ps)
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }
    
    vector<int> pick() {
        int k = rand()%ps[n-1]; 
        cout<<"k = "<<k<<endl;
        int idx = lower_bound(ps.begin(), ps.end(), k+1) - ps.begin();
        cout<<idx<<endl;
        k -= (idx > 0 ? ps[idx-1] : 0); 
        int width = rects[idx][2]-rects[idx][0]+1; 
        return {rects[idx][0] + k%width, rects[idx][1] + k/width}; 
    }
};

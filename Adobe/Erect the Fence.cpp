
long double slope(long long x, long long y, long long a, long long b){
	return (long double)(y - b) / (x - a);
}
class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& pts) {
        int n = pts.size();
        #define ff first
        #define ss second
        vector<pair<int, int>> p(n);
        for(int i = 0; i < n; i++) p[i] = {pts[i][0], pts[i][1]};
        sort(p.begin(), p.end());
        vector<int> U(n), D(n), v;
        vector<long double> s(1, -1E18);
        for(int i = 0; i < n; i++){
            auto [x, y] = p[i];
            if(!v.empty()){
                while(slope(x, y, p[v.back()].ff, p[v.back()].ss) < s.back()) D[v.back()] = 0, v.pop_back(), s.pop_back();
                s.push_back(slope(p[i].ff, p[i].ss, p[v.back()].ff, p[v.back()].ss));
            }
            v.push_back(i), D[i] = 1;
            while(i + 1 < n && p[i + 1].ff == p[i].ff) i += 1;
        }
        s.clear(), v.clear();
        s.push_back(1E18);
        for(int i = 0; i < n; i++){
            while(i + 1 < n && p[i + 1].ff == p[i].ff) i += 1;
            auto [x, y] = p[i];
            if(!v.empty()){
                while(slope(x, y, p[v.back()].ff, p[v.back()].ss) > s.back()) U[v.back()] = 0, v.pop_back(), s.pop_back();
                s.push_back(slope(p[i].ff, p[i].ss, p[v.back()].ff, p[v.back()].ss));
            }
            v.push_back(i), U[i] = 1;
        }
        int ans = 0;
        while(ans + 1 < n && p[ans].ff == p[ans + 1].ff) U[ans += 1] = 1;
        ans = n - 1;
        while(ans - 1 >= 0 && p[ans].ff == p[ans - 1].ff) U[ans -= 1] = 1;
        ans = 0;
        for(int i = 0; i < n; i++) if(U[i] || D[i]) ans += 1, U[i] |= D[i];
        vector<vector<int>> res;
        for(int i = 0; i < n; i++){
            if(U[i]) res.push_back({p[i].ff, p[i].ss});
        }
        return res;
    }
};

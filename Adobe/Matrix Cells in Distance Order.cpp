class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        int n = R*C, ctr = 0;
        const int dirnum = 4;

        int dir[dirnum][2] = {{0,-1}, {-1,0}, {0,1}, {1,0}};
        queue<vector<int>> q;
        vector<int> visited(n);
        q.push({r0,c0});
        visited[r0*C + c0] = 1;
        vector<vector<int>> ans(n);
        while(!q.empty())
        {
            ans[ctr++] = q.front();  
            q.pop();
            for(int i=0; i<dirnum; ++i)
            {
                int r = ans[ctr-1][0] + dir[i][0];
                int c = ans[ctr-1][1] + dir[i][1];
                if(r>=0 && r<R && c>=0 && c<C && visited[r*C + c] == 0) 
                {
                    q.push({r,c});
                    visited[r*C + c] = 1;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    bool isValid(int x, int y, vector<vector<int>> &grid){
        int m = grid.size();
        int n = grid[0].size();

        return (x >= 0 && x < m && y >= 0 && y < n);
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> ans(m, vector<int>(n, -1));
        vector<vector<int>> vis(m, vector<int>(n, 0));

        vector<int> delx = {0, -1, 0, 1};
        vector<int> dely = {-1, 0, 1, 0};

        queue<pair<int, int>> q;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(isWater[i][j] == 1){
                    ans[i][j] = 0;
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second;

            for(int i = 0; i < 4; i++){
                int newx = x + delx[i];
                int newy = y + dely[i];

if(isValid(newx, newy, isWater) && vis[newx][newy] == 0){
                    ans[newx][newy] = ans[x][y] + 1;
                    q.push({newx, newy});
                    vis[newx][newy] = 1;
                }

            }
        }

        return ans;
    }
};

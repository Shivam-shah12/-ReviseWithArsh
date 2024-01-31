class Solution {
public:
    vector<int>dx = {1, 0, -1, 0};
    vector<int>dy = {0, 1, 0, -1};
    
    int number_of_island(vector<vector<int>>&grid, int row, int col)
    {
        vector<vector<int>>vis(row, vector<int>(col, 0));
        int count = 0; //number of island
        queue<pair<int, int>>q;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1 && vis[i][j] == 0)
                {
                    vis[i][j] = 1;
                    q.push({i,j});
                    count++;
                    while(!q.empty())
                    {
                        int sz = q.size();
                        while(sz--)
                        {
                            auto curr = q.front(); q.pop();
                            int f = curr.first;
                            int s = curr.second;
                            for(int k=0;k<4;k++)
                            {
                                int u = f + dx[k];
                                int v = s + dy[k];
        if(u < row && u >= 0 && v < col && v >= 0  && grid[u][v] == 1 && vis[u][v] == 0 )
                                {
                                    q.push({u, v});
                                    vis[u][v] =1 ;
                                }
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
    int minDays(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = number_of_island(grid, row, col); // initial number of island
        
        if (count > 1 or count == 0)  //already their are more than one island seperated or it is empty
        {
            return 0;
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                int islands = 0;
                if(grid[i][j]==1)
                {
                    int temp=grid[i][j];
                    grid[i][j]=0; // change land to water
                    
                    islands=number_of_island(grid,row,col);
                    if(islands!=1)
                        return 1; 
                    
                    grid[i][j]=temp; // replace our changed water cell to land 
                }
            }
        }
        return 2;
    }
};

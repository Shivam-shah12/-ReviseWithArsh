class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j){
        int n = grid.size();
        int m = grid[0].size();

        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 'X'){
            return;
        }
        grid[i][j] = 'Y';
        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
    }

    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) {
            return 0;  
        }

        int m = board[0].size();
        if (m == 0) {
            return 0; 
        }

        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'X'){
                    dfs(board, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};

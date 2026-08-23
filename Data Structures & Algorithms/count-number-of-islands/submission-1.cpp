class Solution {
public:
    void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &visited){
        int n = grid.size();
        int m = grid[0].size();

        visited[row][col] = 1;

        queue<pair<int,int>> q;
        q.push({row,col});

        while(!q.empty()){
            auto node = q.front();
            int r = node.first;
            int c = node.second;
            q.pop();

            int dr[4] = {-1, 0, 1, 0};
            int dc[4] = {0, 1, 0, -1};

            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < n &&
                   nc >= 0 && nc < m &&
                   !visited[nr][nc] &&
                   grid[nr][nc] == '1'){

                    visited[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        int cnt = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(!visited[i][j] && grid[i][j] == '1'){
                    bfs(i, j, grid, visited);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
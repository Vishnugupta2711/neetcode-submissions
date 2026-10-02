class Solution {
public:
    void bfs(int i, int j,
             vector<vector<int>>& grid,
             vector<vector<int>>& visited) {

        int m = grid.size();
        int n = grid[0].size();

        visited[i][j] = 1;

        queue<pair<int,int>> q;
        q.push({i,j});

        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};

        while(!q.empty()) {

            auto it = q.front();
            q.pop();

            int r = it.first;
            int c = it.second;

            for(int k = 0; k < 4; k++) {

                int nr = r + delrow[k];
                int nc = c + delcol[k];

                if(nr >= 0 && nr < m &&
                   nc >= 0 && nc < n &&
                   grid[nr][nc] == 1 &&
                   !visited[nr][nc]) {

                    visited[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if((i == 0 || j == 0 || i == m-1 || j == n-1) &&
                   grid[i][j] == 1 &&
                   !visited[i][j]) {

                    bfs(i, j, grid, visited);
                }
            }
        }

        int cnt = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1 && !visited[i][j]) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
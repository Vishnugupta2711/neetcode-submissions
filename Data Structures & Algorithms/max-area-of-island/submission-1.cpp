class Solution {
public:
    int bfs(int row, int col, vector<vector<int>>& grid,
            vector<vector<int>>& visited) {

        int n = grid.size();
        int m = grid[0].size();

        visited[row][col] = 1;

        queue<pair<int,int>> q;
        q.push({row, col});

        int ans = 0;

        while(!q.empty()) {

            auto node = q.front();
            int r = node.first;
            int c = node.second;
            q.pop();

            // Count current island cell
            ans++;

            int dr[4] = {-1, 0, 1, 0};
            int dc[4] = {0, 1, 0, -1};

            for(int i = 0; i < 4; i++) {

                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < n &&
                   nc >= 0 && nc < m &&
                   !visited[nr][nc] &&
                   grid[nr][nc] == 1) {

                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }

        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(
            n, vector<int>(m, 0)
        );

        int maxi = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(!visited[i][j] && grid[i][j] == 1) {

                    int ans = bfs(i, j, grid, visited);

                    maxi = max(maxi, ans);
                }
            }
        }

        return maxi;
    }
};
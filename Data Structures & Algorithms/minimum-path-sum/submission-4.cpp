class Solution {
public:
    int solve(int row, int col,
              vector<vector<int>>& grid,
              vector<vector<int>>& dp) {

        // Starting cell
        if(row == 0 && col == 0) {
            return grid[0][0];
        }

        // Out of bounds
        if(row < 0 || col < 0) {
            return INT_MAX;
        }

        // Already calculated
        if(dp[row][col] != -1) {
            return dp[row][col];
        }

        // Move up
        int up = solve(row - 1, col, grid, dp);

        // Move left
        int left = solve(row, col - 1, grid, dp);

        // Current cell + minimum of both paths
        return dp[row][col] = grid[row][col] + min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m - 1, n - 1, grid, dp);
    }
};
class Solution {
public:

    int solve(int idx, vector<int>& coins, int amount,
              vector<vector<int>>& dp) {

        // Exact amount formed
        if (amount == 0) {
            return 1;
        }

        // No coins left
        if (idx < 0) {
            return 0;
        }

        // Already calculated
        if (dp[idx][amount] != -1) {
            return dp[idx][amount];
        }

        // Current coin is too large
        if (coins[idx] > amount) {
            return dp[idx][amount] =
                solve(idx - 1, coins, amount, dp);
        }

        // Take current coin
        // Stay at idx because coins are unlimited
        int take = solve(
            idx,
            coins,
            amount - coins[idx],
            dp
        );

        // Skip current coin
        int skip = solve(
            idx - 1,
            coins,
            amount,
            dp
        );

        return dp[idx][amount] = take + skip;
    }

    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<int>> dp(
            n,
            vector<int>(amount + 1, -1)
        );

        return solve(n - 1, coins, amount, dp);
    }
};
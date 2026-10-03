class Solution {
public:
    int solve(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (amount == 0)
            return 1;

        if (i == 0) {
            if (amount % coins[0] == 0)
                return 1;
            return 0;
        }

        if(dp[i][amount] != -1)
          return dp[i][amount];

        // Not Pick
        int ex = solve(i - 1, amount, coins, dp);

        // Pick
        int in = 0;
        if (coins[i] <= amount)
            in = solve(i, amount - coins[i], coins, dp);

        return dp[i][amount] = ex + in;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return solve(n - 1, amount, coins, dp);
    }
};
class Solution {
public:
  int solve(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
    if(i == 0) {
        if (amount % coins[0] == 0)
        return amount / coins[0];
        return 1e9;
    }
    if(dp[i][amount] != -1 )
     return dp[i][amount];

    int ex = solve(i - 1, amount, coins, dp);
    int in = 1e9;
    if(coins[i] <= amount)
      in = 1 + solve(i, amount - coins[i], coins, dp);

      return dp[i][amount] =  min(ex, in);

  }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = solve(n -1, amount, coins, dp);

        if(ans >= 1e9)
          return -1;

          return ans;
        
    }
};
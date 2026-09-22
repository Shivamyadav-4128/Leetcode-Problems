class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));

        for(int a = 0; a <= amount; a++){
            if(a % coins[0] == 0)
            dp[0][a] = a / coins[0];
          }
        for(int i = 1; i < n; i++){
            for(int a = 0; a <= amount; a++){

         int ex = dp[i - 1][a];
         int in = 1e9;
         if(coins[i] <= a)
         in = 1 + dp[i][a - coins[i]];

         dp[i][a] = min(ex, in);
            }
        }
          if (dp[n - 1][amount] >= 1e9)
            return -1;

        return dp[n - 1][amount];
        
    }
};
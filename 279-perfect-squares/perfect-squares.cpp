
class Solution {
public:
   int dp[10001];
    int solve(int n) {
        if(n == 0)
            return 0;

        int ans = INT_MAX;

        if(dp[n] != -1){
            return dp[n];
        }

        for(int j = 1; j * j <= n; j++) {
            ans = min(ans, 1 + solve(n - j*j));
        }

        return dp[n] = ans;
    }

    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};

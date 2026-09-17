class Solution {
public:
    int dp[601][101][101];
    int solve(int i, int m, int n, vector<string>& strs) {
        if(i == strs.size())
          return 0;

          if(dp[i][m][n] != -1)
            return dp[i][m][n];
          int z = 0, o = 0;
          for(char c : strs[i]) {
            if(c == '0') z++;
            else o++;
          }
          int ex = solve(i + 1, m, n, strs);
          int in = 0;
          if(z <= m && o <= n)
            in = 1 + solve(i + 1, m - z, n - o, strs);

            return dp[i][m][n] =  max(in, ex);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(0, m, n, strs);
    }
};
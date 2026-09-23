class Solution {
public:
    int dp[1001][1001];
    int fxn(string &s1, string &s2, int i, int j){
        if(i < 0 || j <0)
          return 0;

          if(dp[i][j] != -1)
            return dp[i][j];

        if(s1[i] == s2[j]) 
         return 1 + fxn(s1, s2, i - 1, j - 1);
         else
         return dp[i][j] = max(fxn(s1, s2, i- 1, j), fxn(s1, s2, i, j - 1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        return fxn(text1, text2, text1.size() - 1, text2.size() - 1);
    }
};
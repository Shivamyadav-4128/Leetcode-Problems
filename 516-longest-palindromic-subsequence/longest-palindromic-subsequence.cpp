class Solution {
public:
   int dp[1001][1001];
     int fxn(int i, int j, string &s){
     if(i == j) return 1;
     if(i > j) return 0;

     if(dp[i][j] != -1)
       return dp[i][j];

     if(s[i] == s[j])
       return dp[i][j] = 2 + fxn(i + 1, j - 1, s);
       else
       return dp[i][j] =  max(fxn(i + 1,j, s), fxn(i,j - 1, s));
     }
    int longestPalindromeSubseq(string s) {
        memset(dp, -1, sizeof(dp));
        return fxn(0, s.size() - 1, s);
    }
};
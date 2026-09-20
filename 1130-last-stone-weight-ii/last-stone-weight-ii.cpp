class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int diff, vector<int>& stones, int total) {
        if (i == stones.size())
            return abs(diff);

        if (dp[i][diff + total] != -1)
            return dp[i][diff + total];

        int pick = solve(i + 1, diff + stones[i], stones, total);
        int notPick = solve(i + 1, diff - stones[i], stones, total);

        return dp[i][diff + total] = min(pick, notPick);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int total = 0;

        for (int x : stones)
            total += x;

        dp.assign(stones.size(), vector<int>(2 * total + 1, -1));

        return solve(0, 0, stones, total);
    }
};
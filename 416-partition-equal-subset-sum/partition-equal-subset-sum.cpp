
class Solution {
public:
   int dp[201][10001];
    bool fxn(vector<int>& arr, int i, int cs, int ts) {
        if (cs == ts / 2) return true;
        if (i < 0 || cs > ts / 2) return false;

        if(dp[i][cs] != -1)
          return dp[i][cs];

        // Ex
        bool ex = fxn(arr, i - 1, cs, ts);

        // In
        bool in = false;
        if(cs + arr[i] <= ts / 2)
          in = fxn(arr, i - 1, cs + arr[i], ts);

        return dp[i][cs] =  in || ex;
    }

    bool canPartition(vector<int>& nums) {
        int ts = 0;

        for (int x : nums)
            ts += x;

        if (ts % 2 != 0) return false;
        memset(dp, -1, sizeof(dp));

        return fxn(nums, nums.size() - 1, 0, ts);
    }
};
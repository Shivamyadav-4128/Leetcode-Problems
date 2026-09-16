
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int ts = 0;

        for (int x : nums)
            ts += x;

        if (ts % 2 != 0) return false;

        int target = ts / 2;

        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        for(int i = 0; i <= n; i++)   //bc
            dp[i][0] = true;

            for(int i = 1; i <= n; i++){
                for(int cs = 1; cs <= target; cs++){

                    bool ex = dp[i - 1][cs];

                    bool in = false;
                    if(nums[i - 1] <= cs)
                      in = dp[i - 1][cs - nums[i - 1]];

                      dp[i][cs] = in || ex;
                }
            }
            return dp[n][target];
    }
};
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);
        vector<int> parent(n, -1);
        int maxi = 1;
        int last = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){

                if(nums[i] % nums[j] == 0){

                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                last = i;
            }
        }
        vector<int> ans;
        int it = last;
        while(it != -1){
            ans.push_back(nums[it]);
            it = parent[it];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            long long p = 1, l = 1;
            int g = 0;

            for(int j = i; j < n; j++){

                if(p > 2520 / nums[j])
                    break;
                    
                p *= nums[j];
                g = gcd(g, nums[j]);
                l = lcm(l, (long long)nums[j]);

                if(p == g * l)
                ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
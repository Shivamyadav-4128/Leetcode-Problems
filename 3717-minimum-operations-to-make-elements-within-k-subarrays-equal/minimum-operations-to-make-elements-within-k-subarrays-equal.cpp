class Solution {
public:
    multiset<int> leftSet, rightSet;
    long long sumL = 0, sumR = 0;

    void balance() {
        int target = (leftSet.size() + rightSet.size() + 1) / 2;

        while (leftSet.size() > target) {
            int val = *leftSet.rbegin();
            leftSet.erase(leftSet.find(val));
            sumL -= val;

            rightSet.insert(val);
            sumR += val;
        }

        while (leftSet.size() < target) {
            int val = *rightSet.begin();
            rightSet.erase(rightSet.find(val));
            sumR -= val;

            leftSet.insert(val);
            sumL += val;
        }
    }

    void add(int val) {
        if (leftSet.empty() || val <= *leftSet.rbegin()) {
            leftSet.insert(val);
            sumL += val;
        } else {
            rightSet.insert(val);
            sumR += val;
        }

        balance();
    }

    void remove(int val) {
        auto it = leftSet.find(val);

        if (it != leftSet.end()) {
            leftSet.erase(it);
            sumL -= val;
        } else {
            it = rightSet.find(val);
            rightSet.erase(it);
            sumR -= val;
        }

        balance();
    }

    long long getCost() {
        long long median = *leftSet.rbegin();

        return median * leftSet.size() - sumL
             + sumR - median * rightSet.size();
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<long long> cost(n - x + 1);

        // Step 1: Calculate sliding window costs

        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }

        cost[0] = getCost();

        for (int i = x; i < n; i++) {
            remove(nums[i - x]);
            add(nums[i]);

            cost[i - x + 1] = getCost();
        }

        // Step 2: DP

        const long long INF = 1e18;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {

                // Skip current element
                curr[i] = curr[i - 1];

                // Take a window of size x
                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev = curr;
        }

        return prev[n];
    }
};
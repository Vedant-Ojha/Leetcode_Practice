class Solution {
public:
    long long climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n + 1, LLONG_MAX);

        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            long long best = dp[i - 1] + 1;

            if (i >= 2) best = min(best, dp[i - 2] + 4);
            if (i >= 3) best = min(best, dp[i - 3] + 9);

            dp[i] = best + costs[i - 1];
        }

        return dp[n];
    }
};
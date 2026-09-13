class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2) return false;
        int target = total / 2;
        vector<char> dp(target + 1);
        dp[0] = 1;
        for (int num : nums)
            for (int j = target; j >= num; j--)
                dp[j] |= dp[j - num];
        return dp[target];
    }
};
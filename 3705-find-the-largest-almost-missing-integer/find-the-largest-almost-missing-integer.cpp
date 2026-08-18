class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int cnt[51] = {}, n = nums.size();

        for (int i = 0; i <= n - k; ++i) {
            int seen[51] = {};
            for (int j = i; j < i + k; ++j)
                seen[nums[j]] = 1;
            for (int x = 0; x <= 50; ++x)
                cnt[x] += seen[x];
        }
        for (int x = 50; x >= 0; --x)
            if (cnt[x] == 1)
                return x;

        return -1;
    }
};
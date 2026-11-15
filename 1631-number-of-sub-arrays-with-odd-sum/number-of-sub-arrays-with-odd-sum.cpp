class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;

        long long even = 1;
        long long odd = 0;
        long long ans = 0;

        int parity = 0;

        for (int x : arr) {
            parity = (parity + x) % 2;

            if (parity & 1) {
                ans = (ans + even) % MOD;
                odd++;
            } else {
                ans = (ans + odd) % MOD;
                even++;
            }
        }

        return ans % MOD;
    }
};

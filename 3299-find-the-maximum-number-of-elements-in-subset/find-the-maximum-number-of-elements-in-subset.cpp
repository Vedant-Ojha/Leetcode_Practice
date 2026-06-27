class Solution {
public:
    typedef long long ll;

    int maximumLength(vector<int>& nums) {
        unordered_map<ll, int> freq;
        for (int num : nums) freq[num]++;

        int result = 0;
        if (freq.count(1)) {
            if (freq[1] % 2 == 1) result = freq[1];
            else result = freq[1] - 1;
        }
        for (auto &[num, _] : freq) {
            if (num == 1) continue;

            ll curr = num;
            int len = 0;

            while (freq.count(curr) && freq[curr] > 1) {
                len += 2;
                curr = curr * curr;
                if (curr > 1e18) break; 
            }

            if (freq.count(curr)) {
                len += 1;
            } else {
                len -= 1;
            }

            result = max(result, len);
        }

        return result;
    }
};

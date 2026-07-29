class Solution {
public:
    long long LIMIT;

    long long nCr(int n, int r) {
        if (r > n) return 0;
        r = min(r, n - r);

        long long ans = 1;
        for (int i = 1; i <= r; i++) {
            ans = ans * (n - r + i) / i;
            if (ans >= LIMIT)
                return LIMIT;
        }
        return ans;
    }

    long long countWays(vector<int>& cnt) {
        int letters = 0;
        for (int x : cnt)
            letters += x;

        long long ways = 1;

        int rem = letters;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 0) continue;

            long long comb = nCr(rem, cnt[i]);

            if (ways >= LIMIT || comb >= LIMIT) {
                ways = LIMIT;
            } else {
                if (ways > LIMIT / comb)
                    ways = LIMIT;
                else
                    ways *= comb;

                if (ways > LIMIT)
                    ways = LIMIT;
            }

            rem -= cnt[i];
        }

        return min(ways, LIMIT);
    }

    string smallestPalindrome(string s, int k) {
        LIMIT = k;

        int n = s.size();

        vector<int> cnt(26, 0);
        char mid = 0;

        for (char c : s)
            cnt[c - 'a']++;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] & 1)
                mid = char('a' + i);
            cnt[i] /= 2;
        }

        if (countWays(cnt) < k)
            return "";

        string left = "";
        int half = n / 2;

        for (int pos = 0; pos < half; pos++) {

            for (int c = 0; c < 26; c++) {

                if (cnt[c] == 0)
                    continue;

                cnt[c]--;

                long long ways = countWays(cnt);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break;
                }

                k -= ways;
                cnt[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (n & 1)
            return left + string(1, mid) + right;

        return left + right;
    }
};
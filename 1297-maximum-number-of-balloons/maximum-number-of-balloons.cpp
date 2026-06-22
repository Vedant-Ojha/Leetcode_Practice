class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26, 0);
        for (char c : text) {
            freq[c - 'a']++;
        }
        int count_b = freq['b' - 'a'] / 1;
        int count_a = freq['a' - 'a'] / 1;
        int count_l = freq['l' - 'a'] / 2;
        int count_o = freq['o' - 'a'] / 2;
        int count_n = freq['n' - 'a'] / 1;

        return min({count_b, count_a, count_l, count_o, count_n});
    }
};
class Solution {
public:
    int countCommas(int n) {
        int total = 0;

        if (n >= 1000) {
            total += min(n, 9999) - 999;
        }
        if (n >= 10000) {
            total += min(n, 99999) - 9999;
        }
        if (n >= 100000) {
            total += n - 100000+1;
        }

        return total;
    }
};
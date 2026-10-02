class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> list;
        solve(n, 0, 0, "", list);
        return list;
    }

    void solve(int n, int open, int close, string ans, vector<string>& list) {
        if (open == n && close == n) {
            list.push_back(ans);
            return;
        }

        if (open < n) {
            solve(n, open + 1, close, ans + "(", list);
        }

        if (close < open) {
            solve(n, open, close + 1, ans + ")", list);
        }
    }
};
class Solution {
public:
    static constexpr long long MOD = 1000000007LL;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int m = A.size();
        Matrix C(m, vector<long long>(m, 0));

        for (int i = 0; i < m; i++) {
            for (int k = 0; k < m; k++) {
                if (A[i][k] == 0) continue;

                for (int j = 0; j < m; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int m = base.size();

        Matrix res(m, vector<long long>(m, 0));
        for (int i = 0; i < m; i++) {
            res[i][i] = 1;
        }

        while (exp) {
            if (exp & 1) {
                res = multiply(res, base);
            }

            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        Matrix T(m, vector<long long>(m, 0));

        // Transition matrix
        for (int j = 0; j < m; j++) {
            for (int i = m - j; i < m; i++) {
                T[i][j] = 1;
            }
        }

        Matrix P = power(T, n - 1);

        long long ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                ans = (ans + P[i][j]) % MOD;
            }
        }

        return (int)(ans * 2 % MOD);
    }
};
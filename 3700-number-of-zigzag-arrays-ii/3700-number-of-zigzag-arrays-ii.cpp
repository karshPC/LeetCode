class Solution {
public:
    static const int MOD = 1e9 + 7;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                for (int j = 0; j < n; j++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix A, long long p) {
        int n = A.size();
        Matrix res(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++)
            res[i][i] = 1;

        while (p > 0) {
            if (p & 1)
                res = multiply(res, A);

            A = multiply(A, A);
            p >>= 1;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int sz = 2 * m;

        Matrix T(sz, vector<long long>(sz, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (j < i)
                    T[i][m + j] = 1;

                if (j > i)
                    T[m + i][j] = 1;
            }
        }

        vector<long long> dp(sz, 0);

        for (int i = 0; i < m; i++) {
            dp[i] = i;
            dp[m + i] = m - 1 - i;
        }

        Matrix P = power(T, n - 2);

        vector<long long> ans(sz, 0);

        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                ans[i] = (ans[i] + P[i][j] * dp[j]) % MOD;
            }
        }

        long long res = 0;

        for (long long x : ans)
            res = (res + x) % MOD;

        return res;
    }
};
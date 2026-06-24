class Solution {
public:
    static const long long MOD = 1000000007;

    vector<vector<long long>> multiply(vector<vector<long long>>& a,
                                       vector<vector<long long>>& b) {
        int n = a.size();
        vector<vector<long long>> res(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (a[i][k]) {
                    for (int j = 0; j < n; j++) {
                        res[i][j] =
                            (res[i][j] + a[i][k] * b[k][j]) % MOD;
                    }
                }
            }
        }
        return res;
    }

    vector<vector<long long>> power(vector<vector<long long>> base,
                                    long long exp) {
        int n = base.size();

        vector<vector<long long>> ans(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++)
            ans[i][i] = 1;

        while (exp) {
            if (exp & 1)
                ans = multiply(ans, base);

            base = multiply(base, base);
            exp >>= 1;
        }

        return ans;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int size = 2 * m;

        vector<long long> dp(size, 0);

        // Arrays of length 2
        for (int i = 0; i < m; i++) {
            dp[i] = i;              // increasing ending at i
            dp[m + i] = m - i - 1;  // decreasing ending at i
        }

        vector<vector<long long>> mat(size, vector<long long>(size, 0));

        for (int i = 0; i < m; i++) {

            // next increasing
            for (int j = 0; j < i; j++) {
                mat[i][m + j] = 1;
            }

            // next decreasing
            for (int j = i + 1; j < m; j++) {
                mat[m + i][j] = 1;
            }
        }

        auto res = power(mat, n - 2);

        vector<long long> finalDp(size, 0);

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                finalDp[i] =
                    (finalDp[i] + res[i][j] * dp[j]) % MOD;
            }
        }

        long long ans = 0;

        for (auto x : finalDp) {
            ans = (ans + x) % MOD;
        }

        return ans;
    }
};
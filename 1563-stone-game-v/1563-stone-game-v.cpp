class Solution {
public:
    int n;
    vector<int> prefix;
    vector<vector<int>> dp;

    int sum(int l, int r) {
        return prefix[r + 1] - prefix[l];
    }

    int solve(int l, int r) {
        if (l == r) return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        int ans = 0;

        for (int k = l; k < r; k++) {
            int left = sum(l, k);
            int right = sum(k + 1, r);

            if (left < right) {
                ans = max(ans, left + solve(l, k));
            }
            else if (right < left) {
                ans = max(ans, right + solve(k + 1, r));
            }
            else {
                ans = max(ans, left + max(solve(l, k), solve(k + 1, r)));
            }
        }

        return dp[l][r] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        n = stoneValue.size();

        prefix.resize(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + stoneValue[i];

        dp.assign(n, vector<int>(n, -1));

        return solve(0, n - 1);
    }
};
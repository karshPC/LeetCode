class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        vector<vector<bool>> pal(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] &&
                    (j - i <= 2 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }

        vector<int> dp(n + 1, INT_MAX);

        dp[0] = -1;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                if (pal[i][j]) {
                    dp[j + 1] = min(dp[j + 1], dp[i] + 1);
                }
            }
        }

        return dp[n];
    }
};
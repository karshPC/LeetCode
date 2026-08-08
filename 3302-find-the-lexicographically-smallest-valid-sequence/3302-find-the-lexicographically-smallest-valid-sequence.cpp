class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> exact(n + 1, 0);
        vector<int> oneMismatch(n + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            exact[i] = exact[i + 1];

            if (exact[i] < m &&
                word1[i] == word2[m - 1 - exact[i]]) {
                ++exact[i];
            }

            oneMismatch[i] = oneMismatch[i + 1];

            if (oneMismatch[i] < m) {
                if (word1[i] == word2[m - 1 - oneMismatch[i]]) {
                    oneMismatch[i] = oneMismatch[i + 1] + 1;
                } else if (exact[i + 1] < m) {
                    oneMismatch[i] = max(
                        oneMismatch[i],
                        exact[i + 1] + 1
                    );
                }
            }
        }

        vector<int> ans;
        int prev = -1;
        bool mismatchUsed = false;

        for (int j = 0; j < m; ++j) {
            int remaining = m - j - 1;
            bool found = false;

            for (int i = prev + 1; i < n; ++i) {
                if (mismatchUsed) {
                    if (word1[i] == word2[j] &&
                        exact[i + 1] >= remaining) {

                        ans.push_back(i);
                        prev = i;
                        found = true;
                        break;
                    }
                } else {
                    if (word1[i] == word2[j]) {
                        if (oneMismatch[i + 1] >= remaining) {
                            ans.push_back(i);
                            prev = i;
                            found = true;
                            break;
                        }
                    } else {
                        if (exact[i + 1] >= remaining) {
                            ans.push_back(i);
                            prev = i;
                            mismatchUsed = true;
                            found = true;
                            break;
                        }
                    }
                }
            }

            if (!found)
                return {};
        }

        return ans;
    }
};
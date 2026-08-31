class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;

        for (string word : words) {
            int sum = 0;

            for (char c : word) {
                sum += weights[c - 'a'];
            }

            int idx = sum % 26;

            // Reverse alphabetical order:
            // 0 -> z, 1 -> y, ..., 25 -> a
            ans += char('z' - idx);
        }

        return ans;
    }
};
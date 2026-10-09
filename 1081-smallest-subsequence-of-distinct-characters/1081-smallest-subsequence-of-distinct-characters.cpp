class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26, 0);
        vector<bool> seen(26, false);
        string ans;

        for (char c : s)
            freq[c - 'a']++;

        for (char c : s) {
            freq[c - 'a']--;

            if (seen[c - 'a'])
                continue;

            while (!ans.empty() && ans.back() > c && freq[ans.back() - 'a'] > 0) {
                seen[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans += c;
            seen[c - 'a'] = true;
        }

        return ans;
    }
};
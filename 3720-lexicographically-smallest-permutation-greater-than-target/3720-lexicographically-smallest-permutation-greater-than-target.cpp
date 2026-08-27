class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string prefix;

        for (int i = 0; i < n; i++) {
            int x = target[i] - 'a';

            if (freq[x]) {
                prefix += target[i];
                freq[x]--;
            } else {
                for (int c = x + 1; c < 26; c++) {
                    if (!freq[c]) continue;

                    string ans = prefix + char('a' + c);
                    freq[c]--;

                    for (int k = 0; k < 26; k++)
                        ans += string(freq[k], 'a' + k);

                    return ans;
                }
                break;
            }
        }

        for (int i = (int)prefix.size() - 1; i >= 0; i--) {
            freq[prefix[i] - 'a']++;

            int x = target[i] - 'a';

            for (int c = x + 1; c < 26; c++) {
                if (!freq[c]) continue;

                string ans = prefix.substr(0, i) + char('a' + c);
                freq[c]--;

                for (int k = 0; k < 26; k++)
                    ans += string(freq[k], 'a' + k);

                return ans;
            }
        }

        return "";
    }
};
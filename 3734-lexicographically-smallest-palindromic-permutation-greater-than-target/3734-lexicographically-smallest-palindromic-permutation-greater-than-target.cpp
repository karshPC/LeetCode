class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26);

        for (char c : s)
            cnt[c - 'a']++;

        int odd = 0, mid = -1;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] & 1) {
                odd++;
                mid = i;
            }
        }

        if (odd > 1)
            return "";

        int m = n / 2;
        vector<int> half(26);

        for (int i = 0; i < 26; i++)
            half[i] = cnt[i] / 2;

        auto build = [&](const string& left) {
            string res = left;

            if (n & 1)
                res += char('a' + mid);

            for (int i = m - 1; i >= 0; i--)
                res += left[i];

            return res;
        };

        string cur;
        vector<int> rem = half;

        for (int i = 0; i < m; i++) {
            int x = target[i] - 'a';

            if (rem[x] == 0)
                break;

            cur += target[i];
            rem[x]--;
        }

        if ((int)cur.size() == m) {
            string ans = build(cur);

            if (ans > target)
                return ans;
        }

        for (int i = m - 1; i >= 0; i--) {
            vector<int> r = half;
            string left;
            bool ok = true;

            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                if (r[x] == 0) {
                    ok = false;
                    break;
                }

                left += target[j];
                r[x]--;
            }

            if (!ok)
                continue;

            int x = target[i] - 'a';

            for (int c = x + 1; c < 26; c++) {
                if (r[c] == 0)
                    continue;

                string candidate = left;
                candidate += char('a' + c);
                r[c]--;

                for (int k = 0; k < 26; k++) {
                    while (r[k] > 0) {
                        candidate += char('a' + k);
                        r[k]--;
                    }
                }

                string ans = build(candidate);

                if (ans > target)
                    return ans;

                r = half;

                for (int j = 0; j < i; j++)
                    r[target[j] - 'a']--;

                break;
            }
        }

        return "";
    }
};
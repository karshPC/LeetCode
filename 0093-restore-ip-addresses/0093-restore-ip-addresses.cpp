class Solution {
public:
    vector<string> ans;
    vector<string> parts;

    void solve(string& s, int idx, int count) {
        if (count == 4) {
            if (idx == s.size()) {
                ans.push_back(parts[0] + "." + parts[1] + "." + parts[2] + "." + parts[3]);
            }
            return;
        }

        for (int len = 1; len <= 3 && idx + len <= s.size(); len++) {
            string part = s.substr(idx, len);

            if (part[0] == '0' && len > 1)
                break;

            if (stoi(part) > 255)
                break;

            parts.push_back(part);

            solve(s, idx + len, count + 1);

            parts.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {
        solve(s, 0, 0);
        return ans;
    }
};
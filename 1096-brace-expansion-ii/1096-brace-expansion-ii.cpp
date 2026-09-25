class Solution {
public:
    set<string> parse(string &s, int &i) {
        set<string> res;
        set<string> cur = {""};

        while (i < s.size() && s[i] != '}') {
            if (s[i] == ',') {
                for (auto &x : cur)
                    res.insert(x);

                cur = {""};
                i++;
            }
            else if (s[i] == '{') {
                i++;

                set<string> inside = parse(s, i);

                i++;

                set<string> next;

                for (auto &a : cur) {
                    for (auto &b : inside) {
                        next.insert(a + b);
                    }
                }

                cur = next;
            }
            else {
                char c = s[i];
                i++;

                set<string> next;

                for (auto &x : cur)
                    next.insert(x + c);

                cur = next;
            }
        }

        for (auto &x : cur)
            res.insert(x);

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> ans = parse(expression, i);
        return vector<string>(ans.begin(), ans.end());
    }
};
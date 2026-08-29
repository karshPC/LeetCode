class Solution {
public:
    vector<int> parent, rankv;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;

        if (rankv[a] < rankv[b])
            swap(a, b);

        parent[b] = a;

        if (rankv[a] == rankv[b])
            rankv[a]++;
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();

        parent.resize(n);
        rankv.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto &p : pairs)
            unite(p[0], p[1]);

        vector<vector<int>> groups(n);

        for (int i = 0; i < n; i++)
            groups[find(i)].push_back(i);

        for (int i = 0; i < n; i++) {
            if (groups[i].empty())
                continue;

            string chars;

            for (int idx : groups[i])
                chars += s[idx];

            sort(chars.begin(), chars.end());

            sort(groups[i].begin(), groups[i].end());

            for (int j = 0; j < groups[i].size(); j++)
                s[groups[i][j]] = chars[j];
        }

        return s;
    }
};
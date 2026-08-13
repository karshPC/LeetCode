class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        
        // Segment tree stores the longest, prefix, and suffix
        // equal-character run for each segment.
        struct Node {
            int len, pref, suff, best;
            char lc, rc;
        };
        
        vector<Node> tree(4 * n);
        
        auto merge = [](Node a, Node b) {
            Node res;
            res.len = a.len + b.len;
            res.lc = a.lc;
            res.rc = b.rc;
            
            res.pref = a.pref;
            if (a.pref == a.len && a.rc == b.lc)
                res.pref = a.len + b.pref;
            
            res.suff = b.suff;
            if (b.suff == b.len && a.rc == b.lc)
                res.suff = b.len + a.suff;
            
            res.best = max(a.best, b.best);
            if (a.rc == b.lc)
                res.best = max(res.best, a.suff + b.pref);
            
            return res;
        };
        
        function<void(int,int,int)> build = [&](int node, int l, int r) {
            if (l == r) {
                tree[node] = {1, 1, 1, 1, s[l], s[l]};
                return;
            }
            
            int mid = (l + r) / 2;
            build(node * 2, l, mid);
            build(node * 2 + 1, mid + 1, r);
            tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
        };
        
        function<void(int,int,int,int,char)> update =
            [&](int node, int l, int r, int idx, char c) {
                if (l == r) {
                    tree[node] = {1, 1, 1, 1, c, c};
                    return;
                }
                
                int mid = (l + r) / 2;
                
                if (idx <= mid)
                    update(node * 2, l, mid, idx, c);
                else
                    update(node * 2 + 1, mid + 1, r, idx, c);
                
                tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
            };
        
        build(1, 0, n - 1);
        
        vector<int> ans;
        
        for (int i = 0; i < queryIndices.size(); i++) {
            int idx = queryIndices[i];
            char c = queryCharacters[i];
            
            update(1, 0, n - 1, idx, c);
            ans.push_back(tree[1].best);
        }
        
        return ans;
    }
};
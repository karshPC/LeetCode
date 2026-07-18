class Solution {
public:

    struct cmp{
        bool operator()(pair<int,int> &a, pair<int,int> &b){
            if (a.first == b.first){
                return a.second < b.second;
            }
            return a.first < b.first;
        }
    };

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        int n = mat.size();

        for(int i = 0; i < n; i++){
            pq.push({count(mat[i].begin(), mat[i].end(),1), i});
            if (pq.size() >k){
                pq.pop();
            }
        }

        vector<int> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

    return ans;
    }
};
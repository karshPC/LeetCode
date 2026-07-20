class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        int n = profits.size();

        vector<vector<int>> capPro;

        for (int i = 0; i < n; i++) {
            capPro.push_back({capital[i], profits[i]});
        }

        sort(capPro.begin(), capPro.end());

        priority_queue<int> pq;
        int idx = 0;

        for (int i = 0; i < k; i++) {

            while (idx < n && capPro[idx][0] <= w) {
                pq.push(capPro[idx][1]);
                idx++;
            }

            if (pq.empty())
                break;

            w += pq.top();
            pq.pop();
        }

        return w;
    }
};
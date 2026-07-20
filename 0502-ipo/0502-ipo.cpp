class Solution {
public:

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<vector<int>> capAndPro;

        for(int i = 0; i < profits.size(); i++){
            capAndPro.push_back({capital[i], profits[i]});
        }

        sort(capAndPro.begin(), capAndPro.end());

        int idx = 0;

        priority_queue<int> pq;

        for (int i = 0; i < k; i++) {
            while (idx < n && capAndPro[idx][0] <= w) {
                pq.push(capAndPro[idx][1]);
                idx++;
            }

            if (pq.empty()) {
                break;
            }

            w += pq.top();
            pq.pop();
        }

        return w;
    }
};
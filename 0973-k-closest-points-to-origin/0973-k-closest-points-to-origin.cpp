class Solution {
public:
    struct cmp{
        bool operator()(pair<int,pair<int,int>> &a, pair<int,pair<int,int>> &b){
            return a.first < b.first;
        }
    };

    int distance(int x, int y){
        return x*x + y*y;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, cmp> pq;

        for (auto &point : points){
            pq.push({distance(point[0],point[1]),{point[0], point[1]}});
            if (pq.size() > k){
                pq.pop();
            }
        }

        vector<vector<int>> ans;

        while(!pq.empty()){
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
    
    return ans;
    }
};
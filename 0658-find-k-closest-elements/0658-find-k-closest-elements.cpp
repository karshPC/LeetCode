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

    int distance(int x, int y){
        if (x < y) return y-x;
        return x-y;
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

        for(int ar : arr){
            pq.push({distance(x, ar), ar});
            if (pq.size() >k){
                pq.pop();
            }
        }

        vector<int> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        sort(ans.begin(), ans.end());

    return ans;
    }
};
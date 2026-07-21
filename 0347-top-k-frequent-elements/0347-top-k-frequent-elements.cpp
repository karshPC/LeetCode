class Solution {
public: 
    struct cmp{
        bool operator()(pair<int,int> &a, pair<int,int> &b){
        if (a.first == b.first){
            return a.second > b.second;
        }
        return a.first > b.first;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> freq;

        for (int num : nums){
            freq[num]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

        for (auto &it : freq){
            pq.push({it.second, it.first});
            if (pq.size() > k){
                pq.pop();
            }
        }

        vector<int> res;

        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }

    return res;
    }
};
class Solution {
public:

    struct cmp{
        bool operator()(const pair<int,int> &a, const pair<int,int> &b){
            if (a.first == b.first){
                return a.second > b.second;
            }
            return a.first > b.first;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

        unordered_map<int,int> freq;

        for(int num : nums){
            freq[num]++;
        }
        
        for(auto &it : freq){
            pq.push({it.second, it.first});
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

    return ans;
    }
};
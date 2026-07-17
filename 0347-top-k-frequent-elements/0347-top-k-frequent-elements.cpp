class Solution {
public:
    struct cmp{
        bool operator()(pair<int,int> &a, pair<int,int> &b){
            if (a.first == b.first){
                return a.first > b.first;
            }
            return a.first > b.first;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        for(int num : nums){
            freq[num]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>, cmp> pq;

        for(auto i = freq.begin(); i != freq.end(); i++){
            pq.emplace(i->second, i->first);
            if (pq.size() > k){
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
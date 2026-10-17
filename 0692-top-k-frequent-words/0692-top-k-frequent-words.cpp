class Solution {
public:

    struct cmp{
        bool operator()(pair<string, int>&a, pair<string,int> &b){
            if(a.second != b.second){
                return a.second > b.second;
            }
        return a.first < b.first;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<string,int>, vector<pair<string,int>>, cmp> pq;

        unordered_map<string,int> freq;

        for(string word : words){
            freq[word]++;
        }

        for(auto it : freq){
            pq.push({it.first, it.second});
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<string> res;

        while(!pq.empty()){
            res.push_back(pq.top().first);
            pq.pop();
        }

        reverse(res.begin(),res.end());

    return res;
    }
};
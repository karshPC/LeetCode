class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted_unique = arr;
        sort(sorted_unique.begin(), sorted_unique.end());
        sorted_unique.erase(unique(sorted_unique.begin(), sorted_unique.end()), sorted_unique.end());
        
        unordered_map<int, int> rank_map;
        for (int i = 0; i < sorted_unique.size(); ++i) {
            rank_map[sorted_unique[i]] = i + 1;
        }
        
        vector<int> result;
        for (int num : arr) {
            result.push_back(rank_map[num]);
        }
        
        return result;
    }
};

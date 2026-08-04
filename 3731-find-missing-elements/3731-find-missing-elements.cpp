class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> res;
        int min = *min_element(nums.begin(), nums.end());
        int max = *max_element(nums.begin(), nums.end());
        for(int i = min; i <= max; i++){
            if(find(nums.begin(), nums.end(), i) == nums.end()){
                res.push_back(i);
            }
        }

    return res;
    }
};
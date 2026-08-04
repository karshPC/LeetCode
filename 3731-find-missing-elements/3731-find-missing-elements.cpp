class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> res;
        unordered_set<int> st;

        for(int i = 0; i < nums.size(); i++){
            st.insert(nums[i]);
        }

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        for(int i = mn; i < mx; i++){
            if(st.find(i) == st.end()) res.push_back(i);
        }

    return res;
    }   
};
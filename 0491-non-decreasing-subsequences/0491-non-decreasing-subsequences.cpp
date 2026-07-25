class Solution {
public:
    int n;

    void solve(vector<int> &nums, int idx, vector<int> &curr, vector<vector<int>> &res){

        if(curr.size() >= 2)
            res.push_back(curr);

        unordered_set<int> st;

        for(int i = idx; i < n; i++){
            if((curr.empty() || curr.back() <= nums[i]) &&
               st.find(nums[i]) == st.end()){

                st.insert(nums[i]);
                curr.push_back(nums[i]);
                solve(nums, i + 1, curr, res);
                curr.pop_back();
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        vector<int> curr;
        vector<vector<int>> res;
        solve(nums, 0, curr, res);
        return res;
    }
};
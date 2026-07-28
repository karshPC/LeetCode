class Solution {
public:
    int n;

    void solve(vector<int> &nums, int idx, vector<bool> &used, vector<int> &curr, vector<vector<int>> &res){
        if(idx == n){
            res.push_back(curr);
            return;
        }
        
        for (int i = 0; i < n; i++){
            if(used[i] == true) continue;

            used[i] = true;
            curr.push_back(nums[i]);
            solve(nums, idx+1, used, curr, res);
            curr.pop_back();
            used[i] = false;
        }

    return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int idx = 0;
        n = nums.size();
        vector<bool> used(nums.size(), false);
        vector<int> curr;
        vector<vector<int>> res;
        solve(nums, idx, used, curr, res);
    return res;
    }
};
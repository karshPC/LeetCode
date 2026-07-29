class Solution {
public:

    void solve(vector<int>& candidates, int target,int idx, int sum,vector<int> &curr, vector<vector<int>> &res){
        if(sum == target){
            res.push_back(curr);
            return;
        }

        if(idx == candidates.size()){
            return;
        }

        solve(candidates, target, idx+1, sum, curr, res);

        if(candidates[idx] + sum <= target){
            curr.push_back(candidates[idx]);
            sum += candidates[idx];
            solve(candidates, target, idx, sum, curr, res);
            sum -= candidates[idx];
            curr.pop_back();
        }
    return;
    }   

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int idx = 0;
        int sum = 0;
        vector<int> curr;
        vector<vector<int>> res;
        solve(candidates, target, idx, sum, curr, res);
    return res;
    }
};
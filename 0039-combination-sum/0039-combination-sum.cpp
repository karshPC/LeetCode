class Solution {
public: 

    void solve(vector<int>& candidates, int target, int idx, vector<int> &diary, vector<vector<int>> &res, int sum){

        if(sum == target){
            res.push_back(diary);
            return;
        }

        if(idx == candidates.size()){
            return;
        }

        solve(candidates, target, idx+1, diary, res, sum); // Mat Lo

        if(candidates[idx] + sum <= target){
            diary.push_back(candidates[idx]);
            sum += candidates[idx];
            solve(candidates, target, idx, diary, res, sum);
            sum -= candidates[idx];
            diary.pop_back();
        }

    return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int idx = 0;
        vector<int> diary;
        vector<vector<int>> res;
        int sum=0;
        solve(candidates, target, idx, diary, res, sum);
        
    return res;
    }
};
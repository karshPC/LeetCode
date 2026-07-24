class Solution {
public:

    void solve(vector<int> &candidates, int target, int idx, vector<int> &diary, int sum,
               vector<vector<int>> &res){

        if (sum == target){
                res.push_back(diary);
                return;
            }
        
        if(idx == candidates.size()){
            return;
        }

        solve(candidates, target, idx+1, diary, sum, res); //nahi lena

        if(candidates[idx]+ sum <=target){ // Lena Hai
            diary.push_back(candidates[idx]);
            sum += candidates[idx];
            solve(candidates, target, idx, diary, sum, res);
            sum -= candidates[idx];
            diary.pop_back();
        }
    return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int idx = 0;
        int sum =0;
        vector<int> diary;
        vector<vector<int>> res;
        solve(candidates, target, idx, diary, sum, res);
    
    return res;
    }
};
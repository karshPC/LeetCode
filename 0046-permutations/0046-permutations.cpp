class Solution {
public:

    void solve(vector<int> &nums, int idx, vector<int> &diary, vector<bool> &used,vector<vector<int>> &res){

        if(idx == nums.size()){
            res.push_back(diary);
            return;
        }

        for (int i =0; i<nums.size(); i++){
            if(used[i] == true) continue;

            used[i] = true;
            diary.push_back(nums[i]);
            solve(nums, idx+1, diary,used, res);
            diary.pop_back();
            used[i] = false;

        }    
        
    return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int idx = 0;
        vector<int> diary;
        
        vector<bool> used(nums.size(), false);
        vector<vector<int>> res;

        solve(nums, idx, diary, used, res);
    return res;
    }
};
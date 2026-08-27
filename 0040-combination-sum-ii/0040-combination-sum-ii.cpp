class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& candidates, int target, int start,
                   vector<int>& curr) {

        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // Skip duplicates at the same recursion level
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            // Since sorted, nothing after this can work
            if (candidates[i] > target)
                break;

            curr.push_back(candidates[i]);

            // i + 1 -> each element can be used only once
            backtrack(candidates, target - candidates[i], i + 1, curr);

            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<int> curr;
        backtrack(candidates, target, 0, curr);

        return ans;
    }
};
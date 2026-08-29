class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int mx = 0, idx = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > mx) {
                mx = nums[i];
                idx = i;
            }
        }

        for (int x : nums) {
            if (x != mx && mx < 2 * x)
                return -1;
        }

        return idx;
    }
};
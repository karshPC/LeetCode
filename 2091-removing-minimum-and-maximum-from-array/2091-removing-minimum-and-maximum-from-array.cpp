class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mn = 0, mx = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[mn])
                mn = i;
            if (nums[i] > nums[mx])
                mx = i;
        }

        if (mn > mx)
            swap(mn, mx);

        int a = mx + 1;
        int b = n - mn;
        int c = mn + 1 + n - mx;

        return min({a, b, c});
    }
};
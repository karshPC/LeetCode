class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;

        unordered_set<int> pairs;
        unordered_set<int> triplets;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                pairs.insert(nums[i] ^ nums[j]);
            }
        }

        for (int p : pairs) {
            for (int x : nums) {
                triplets.insert(p ^ x);
            }
        }

        return triplets.size();
    }
};
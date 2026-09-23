class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long target = total - x;

        if (target < 0)
            return -1;

        int low = 0;
        long long sum = 0;
        int maxLen = -1;

        for (int high = 0; high < n; high++) {
            sum += nums[high];

            while (sum > target && low <= high) {
                sum -= nums[low];
                low++;
            }

            if (sum == target)
                maxLen = max(maxLen, high - low + 1);
        }

        if (maxLen == -1)
            return -1;

        return n - maxLen;
    }
};
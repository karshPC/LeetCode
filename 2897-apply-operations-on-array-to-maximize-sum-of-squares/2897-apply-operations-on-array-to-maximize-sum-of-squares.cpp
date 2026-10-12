class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1000000007;
        vector<int> freq(31, 0);

        for (int num : nums) {
            for (int bit = 0; bit < 31; bit++) {
                if (num & (1 << bit))
                    freq[bit]++;
            }
        }

        long long ans = 0;

        for (int i = 0; i < k; i++) {
            long long num = 0;

            for (int bit = 0; bit < 31; bit++) {
                if (freq[bit] > 0) {
                    num |= (1LL << bit);
                    freq[bit]--;
                }
            }

            ans = (ans + num * num) % MOD;
        }

        return ans;
    }
};
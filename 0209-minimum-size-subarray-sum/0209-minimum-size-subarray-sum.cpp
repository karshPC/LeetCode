class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0, high = 0, n = nums.size(), sum =0, minLen = INT_MAX;

        while(high<n){
            sum+= nums[high];
            while(sum >= target){
                sum -= nums[low];
                int len = high-low+1;
                minLen = min(len,minLen);
                low++;
            }
        high++;
        }

    return (minLen == INT_MAX) ? 0:minLen;
    }
};
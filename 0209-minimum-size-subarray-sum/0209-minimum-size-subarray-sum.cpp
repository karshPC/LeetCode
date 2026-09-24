class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0;
        int minLen = INT_MAX;
        int n = nums.size();
        int sum = 0;

        for(int high = 0; high < n; high++){
            sum += nums[high];

            while(sum >= target){
                int len = high-low+1;
                minLen = min(minLen, len);
                sum -= nums[low];
                low++;
            }
        }
    return (minLen==INT_MAX)? 0 : minLen;
    }
};
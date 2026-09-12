class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), low = 0, high = 0, sum =0, minLen = INT_MAX;
        
        while(high < n){
            sum+= nums[high];
            while(sum>= target){
                int len = high-low+1;
                minLen = min(len, minLen);
                sum -= nums[low];
                low++;
            }
        high++;
        }
    return (minLen == INT_MAX) ? 0 : minLen;
    }
};
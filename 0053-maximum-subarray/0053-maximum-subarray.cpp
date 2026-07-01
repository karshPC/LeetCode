class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestEnd = nums[0];
        int ans = nums[0];

        for (int i = 1; i< nums.size(); i++){
            int v1 = bestEnd + nums[i];
            int v2 = nums[i];

            bestEnd = max(v1,v2);

            ans = max(ans,bestEnd);
        }

    return ans;
    
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
    
        int takenMax = nums[0];

        int n = nums.size();

        for(int i = 1; i < n; i++){
            int solo = nums[i];
            int group = takenMax + nums[i]; 
            
            takenMax = max(solo, group);

            res = max(res, takenMax);
        }
    return res;
    }
};
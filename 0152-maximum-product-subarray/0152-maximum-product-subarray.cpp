class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int maxCurrent = nums[0];
        int minCurrent = nums[0];

        for(int i =1; i < nums.size(); i++){
            int v1 = nums[i];
            int v2 = maxCurrent * nums[i];
            int v3 = minCurrent * nums[i];

            maxCurrent = max(v1,max(v2,v3));
            minCurrent = min(v1,min(v2,v3));

            res = max(res,max(maxCurrent,minCurrent));
        }
    return res;
    }
};
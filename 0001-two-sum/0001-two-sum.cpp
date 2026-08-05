class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> found;

        int n = nums.size();
        
        for(int i =0; i<n ; i++){
            int needed = target - nums[i];
            
            if(found.find(needed) != found.end()){
                return {found[needed], i};
            }
            
            found[nums[i]] = i;
        }
    return {};
    }
};
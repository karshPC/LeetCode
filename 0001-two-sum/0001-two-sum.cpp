class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> f;
        int n = nums.size();

        for(int i = 0; i < n; i++){
        
            int left = target-nums[i];
            
            if(f.find(left) != f.end()){
                return {f[left],i};
            }
            
            f[nums[i]] = i;
        }
    return {};
    }
};
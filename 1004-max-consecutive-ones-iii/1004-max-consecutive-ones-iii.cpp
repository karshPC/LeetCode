class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low = 0;
        int n = nums.size();
        int maxRes = 0;

        unordered_map<int,int> f;

        for(int high = 0; high < n; high++){
            f[nums[high]]++;
            int zero = f[0];

            while(zero > k){
                f[nums[low]]--;
                
                if(f[nums[low]] == 0){
                    f.erase(nums[low]);
                }
                low++;

                zero = f[0];
            }

            int len = high-low+1;
            maxRes = max(maxRes, len);
        }
    return maxRes;
    }
};
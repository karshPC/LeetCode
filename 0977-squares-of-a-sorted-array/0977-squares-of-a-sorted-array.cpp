class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int n = nums.size();
        int right = n-1;
        int idx = n-1;

        vector<int> sorted(n);

        while(left <= right){
            
            int l = abs(nums[left]);
            int r = abs(nums[right]);

            if(l >= r){
                sorted[idx] = l*l;
                left++;
                idx--;   
            }
            else{
                sorted[idx] = r*r;
                idx--;
                right--;
            }
        } 

    return sorted;

    }
};
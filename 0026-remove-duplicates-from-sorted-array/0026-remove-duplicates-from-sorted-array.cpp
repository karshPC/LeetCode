class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int officer = 0;
        int n = nums.size();

        if(n==1) return 1;

        for(int cm = 1; cm <n; cm++){
            if(nums[cm] != nums[cm-1]){
                nums[officer+1] = nums[cm];
                officer++;
            }
        }

    return officer+1;
    }
};
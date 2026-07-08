class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int resLow = -1, resHigh = -1;
        
        while(low<=high){
            int mid = low+ (high-low)/2;

            if (nums[mid] == target){
                resLow = mid;
                high = mid-1;
            }

            else if(nums[mid]<target){
                low=mid+1;
            }

            else{
                high = mid-1;
            }
        }

        low = 0, high = nums.size()-1;

        while(low<=high){
            int mid = low+ (high-low)/2;

            if (nums[mid] == target){
                resHigh = mid;
                low = mid+1;
            }

            else if(nums[mid]<target){
                low=mid+1;
            }

            else{
                high = mid-1;
            }

        }

    return {resLow, resHigh};

    }
};
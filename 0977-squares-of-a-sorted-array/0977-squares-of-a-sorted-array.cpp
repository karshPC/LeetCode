class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> sortedSquare(n);

        int left = 0;
        int right = n-1;
        int pos = n-1;

        while(left <= right){
            long l = abs(nums[left]);
            long r = abs(nums[right]);

            if(l > r){
                sortedSquare[pos] = l*l;
                left++;
            }
            else{
                sortedSquare[pos] = r*r;
                right--;
            }

            pos--;

        }
    return sortedSquare;
    }
};
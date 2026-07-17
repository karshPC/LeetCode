class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int, vector<int>, greater<int>> pq;
        int n = nums.size();

        if (n == 1 && k == 1) return nums[0];

        for(int i = n-1; i>= n-k; i--){
            pq.push(nums[i]);
        }

        for(int i = n-k-1; i >= 0; i--){
            if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            } 

            else{
                continue;
            }

        }
    return pq.top();
    }
};
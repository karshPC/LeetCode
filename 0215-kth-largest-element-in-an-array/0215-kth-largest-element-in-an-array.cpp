class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = nums.size();

        for(int i = n-1; i>= n-k; i--){
            pq.push(nums[i]);
        }

        for(int i = n-k-1; i >=0; i--){
            if(pq.top() >= nums[i]){
                continue;
            }
            else{
                pq.pop();
                pq.push(nums[i]);
            }
        }
    return pq.top();
    }
};
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int withPower = arr[0];
        int withoutPower = arr[0];
        int maxSum = arr[0];

        int n = arr.size();

        for(int i = 1; i < n; i++){
            int v1 = withPower + arr[i];
            int v2 = withoutPower;

            int v3 = withoutPower + arr[i];
            int v4 = arr[i];

            withPower = max(v1,v2);
            withoutPower = max(v3,v4);

            maxSum = max(maxSum, max(withPower, withoutPower));

        }
    return maxSum;
    }
};
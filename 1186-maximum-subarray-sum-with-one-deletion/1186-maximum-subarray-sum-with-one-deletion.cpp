class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int withPower = arr[0];
        int withoutPower = arr[0];
        int res = arr[0];

        for(int high = 1; high < n; high++){
            int v1 = arr[high];
            int v2 = withoutPower + arr[high];

            int v3 = withPower + arr[high];
            int v4 = withoutPower;

            withoutPower = max(v1,v2);
            withPower = max(v3,v4);

            res = max(res, max(withoutPower, withPower));
        }
    return res;
    }
};
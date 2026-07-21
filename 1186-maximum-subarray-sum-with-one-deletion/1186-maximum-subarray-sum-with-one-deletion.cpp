class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int res = arr[0];
        int withPower = arr[0];
        int withoutPower = arr[0];
        int n = arr.size();

        for(int i =1; i < n; i++){
            int v1 = arr[i];
            int v2 = withoutPower + arr[i];

            int v3 = withPower + arr[i];
            int v4 = withoutPower;

            withoutPower = max(v1,v2);
            withPower = max(v3,v4);

            res = max(res, max(withPower, withoutPower));
        }
    return res;
    }
};
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int noPower = arr[0];
        int power = arr[0];
        int res = arr[0];

        for(int i = 1; i < arr.size(); i++){
            int v1 = arr[i];
            int v2 = noPower + arr[i];
            int v3 = noPower;
            int v4 = power + arr[i];

            noPower = max(v1,v2);
            power = max(v3,v4);

            res = max(res, max(noPower, power));
            
        }
    return res;
    }
};
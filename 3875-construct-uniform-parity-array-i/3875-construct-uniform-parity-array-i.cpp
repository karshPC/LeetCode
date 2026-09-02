class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd = 0, even = 0;

        for (int x : nums1) {
            if (x & 1)
                odd++;
            else
                even++;
        }

        if (odd == 0 || even == 0)
            return true;

        return true;
    }
};
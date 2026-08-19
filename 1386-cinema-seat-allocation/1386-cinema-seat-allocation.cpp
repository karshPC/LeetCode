class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        for (auto &x : reservedSeats) {
            int row = x[0], seat = x[1];
            mp[row] |= (1 << seat);
        }

        int ans = (n - mp.size()) * 2;

        for (auto &[row, mask] : mp) {
            bool left = true, middle = true, right = true;

            for (int seat = 2; seat <= 5; seat++)
                if (mask & (1 << seat)) left = false;

            for (int seat = 4; seat <= 7; seat++)
                if (mask & (1 << seat)) middle = false;

            for (int seat = 6; seat <= 9; seat++)
                if (mask & (1 << seat)) right = false;

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};
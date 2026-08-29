class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        vector<int> odd, even;

        for (char c : s) {
            int d = c - '0';
            if (d & 1)
                odd.push_back(d);
            else
                even.push_back(d);
        }

        sort(odd.rbegin(), odd.rend());
        sort(even.rbegin(), even.rend());

        int oi = 0, ei = 0;

        for (char &c : s) {
            int d = c - '0';

            if (d & 1)
                c = char('0' + odd[oi++]);
            else
                c = char('0' + even[ei++]);
        }

        return stoi(s);
    }
};
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0, end = 0;
        
        for (int i = 0; i < s.length(); i++) {
            auto [l1, r1] = expand(s, i, i);
            if (r1 - l1 > end - start) {
                start = l1;
                end = r1;
            }
            
            auto [l2, r2] = expand(s, i, i + 1);
            if (r2 - l2 > end - start) {
                start = l2;
                end = r2;
            }
        }
        
        return s.substr(start, end - start + 1);
    }
    
private:
    pair<int, int> expand(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return {left + 1, right - 1};
    }
};
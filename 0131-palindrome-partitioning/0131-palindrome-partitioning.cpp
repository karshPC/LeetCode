class Solution {
public:
    int n;
    
    bool isPalindrome(string &s, int left, int right){
        while(left < right){
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
    return true;
    }

    void solve(string &s, int idx, vector<string> &temp, vector<vector<string>> &res){
        if (idx == n){
            res.push_back(temp);
            return;
        }

        for (int i = idx; i < n; i++){
            if (isPalindrome(s, idx, i)){
                temp.push_back(s.substr(idx, i - idx + 1));
                solve(s, i+1, temp, res);
                temp.pop_back();
            }
        }
    return;
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> res;
        n = s.size();
        int idx = 0;
        solve(s, idx, temp, res);
    return res;
    }
};

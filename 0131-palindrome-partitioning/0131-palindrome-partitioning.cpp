class Solution {
public:
    int n;

    bool isPalindrome(string &s, int left, int right){
        while(left < right){
            if (s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    void solve(string &s, int idx, vector<string> &diary, vector<vector<string>> &res){
        
        if(idx == n){
            res.push_back(diary);
            return;
        }

        for(int i = idx; i < n; i++){
            if(isPalindrome(s, idx, i)){
                diary.push_back(s.substr(idx, i - idx + 1));
                solve(s, i+1, diary, res);
                diary.pop_back();
            }
        }

    return;
    }

    vector<vector<string>> partition(string s) {
        n = s.size();
        int idx = 0;
        vector<string> diary;
        vector<vector<string>> res;
        solve(s, idx, diary, res);
    return res;
    }
};

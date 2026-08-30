class Solution {
public:

    vector<vector<string>> result;

    bool isPalindrome(string &s, int left, int right){
        while(left<right){
            if(s[left]!=s[right]) return false;
            left++;
            right--;
        }
    return true;
    }

    void solve(int idx, int n, vector<string> &temp, string &s){
        if(idx == n){
            result.push_back(temp);
            return;
        }

        for(int i = idx; i <n; i++){
            if(isPalindrome(s, idx, i)){
                temp.push_back(s.substr(idx, i-idx+1));
                solve(i+1, n, temp, s);
                temp.pop_back();            
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string> temp;
        solve(0, n, temp, s);
    return result;
    }
};
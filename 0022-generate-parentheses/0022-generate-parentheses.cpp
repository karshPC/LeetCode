class Solution {
public:  
    void solve(int n, int open, int close, string &temp, vector<string> &res){
        if(open == n && close == n){
            res.push_back(temp);
            return;
        }

        if(open < n){
            temp.push_back('(');
            solve(n, open+1, close, temp, res);
            temp.pop_back();
        }

        if(close < open){
            temp.push_back(')');
            solve(n,open,close+1, temp, res);
            temp.pop_back();
        }
    return;
    }

    vector<string> generateParenthesis(int n) {
        int open = 0;
        int close = 0;
        string temp = "";
        vector<string> res;
        solve(n, open,close,temp,res);
    return res;
    }
};
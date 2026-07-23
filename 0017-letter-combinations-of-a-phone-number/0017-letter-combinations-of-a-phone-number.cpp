class Solution {
public:
    vector<string> res;

    void solve(int idx, string &digits, unordered_map <char, string> &mp,string &temp){
        if (idx == digits.size()){
            res.push_back(temp);
            return;
        }

        string letters = mp[digits[idx]];

        for(char ch : letters){
            temp.push_back(ch);
            solve(idx+1, digits, mp, temp);
            temp.pop_back();
        }
    return;
    }

    vector<string> letterCombinations(string digits) {
        unordered_map <char, string> mp = {
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
        };
        string temp = "";

        solve(0,digits, mp,temp);

        return res;

    }
};
class Solution {
public:

    void solve(string &digits, int idx, string &curr, vector<string> &res, unordered_map<char, string> &mpp){
        if(idx == digits.size()){
            res.push_back(curr);
            return;
        }

        string letters = mpp[digits[idx]];

        for(char letter : letters){
            curr.push_back(letter);
            solve(digits, idx+1, curr, res, mpp);
            curr.pop_back();
        }

    return;
    }

    vector<string> letterCombinations(string digits) {
        
        unordered_map<char, string> mpp{
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5', "jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };

        int idx = 0;
        string curr = "";
        vector<string> res;
        solve(digits, idx, curr, res, mpp);
        return res;
    }
};
class Solution {
public:

    vector<string> res;

    void solve(string &digits, string &temp, int idx, unordered_map<char, string> &mpp){
        
        if(idx == digits.size()){
            res.push_back(temp);
            return;
        }

        string letters = mpp[digits[idx]];

        for(char letter : letters){
            temp.push_back(letter);
            solve(digits, temp, idx+1, mpp);
            temp.pop_back();
        }

    return;
    }

    vector<string> letterCombinations(string digits) {
        int idx = 0;
        unordered_map<char,string> mpp({
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        });
        string temp;
    solve(digits, temp, idx, mpp);

    return res;
    }
};
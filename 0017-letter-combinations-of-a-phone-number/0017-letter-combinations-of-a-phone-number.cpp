class Solution {
public:

    vector<string> ans;

    void solve(int idx, string &digits, string &temp, unordered_map<char,string> mpp){
        if(idx == digits.size()){
            ans.push_back(temp);
            return;
        }

        string letters = mpp[digits[idx]];

        for(char ch : letters){
            temp.push_back(ch);
            solve(idx+1, digits, temp,mpp);
            temp.pop_back();
        }
    return;
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mpp{
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };

        int idx = 0;
        string temp = "";
        solve(idx,digits, temp, mpp);

        return ans;

    }
};
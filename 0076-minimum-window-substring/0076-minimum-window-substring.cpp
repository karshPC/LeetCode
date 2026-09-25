class Solution {
public:

    bool correct(vector<int> &have, vector<int> &needed){
        for(int i = 0; i < 256; i++){
            if(have[i] < needed[i]){
                return false;
            }
        }
    return true;
    }

    string minWindow(string s, string t) {
        vector<int> have(256,0);
        vector<int> needed(256,0);

        int nt = t.size();
        for(int high = 0; high < nt; high++){
            needed[t[high]]++;
        }

        int low = 0;
        int st = s.size();
        int res = INT_MAX;
        int start = 0;
        for(int high = 0; high < st; high++){
            have[s[high]]++;
            while(correct(have,needed)){
                int len = high-low+1;
                if(len < res){
                    res = len;
                    start = low;
                }
                have[s[low]]--;
                low++;
            }
        }       
    return (res == INT_MAX) ? "" : s.substr(start, res);
    }
};
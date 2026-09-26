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
        
        vector<int> needed(256,0);
        int nt = t.size();

        for(int high =0; high < nt; high++){
            needed[t[high]]++;
        }

        vector<int> have(256,0);
        int low = 0;
        int ns = s.size();
        int start = 0;
        int res = INT_MAX;

        for(int high =0; high < ns; high++){
            have[s[high]]++;

            while(correct(have,needed)){
                int len = high-low+1;
                if(res > len){
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
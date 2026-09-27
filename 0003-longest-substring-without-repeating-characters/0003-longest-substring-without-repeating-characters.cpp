class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0;
        int maxLen = 0;
        unordered_map<char,int> f;
        int n = s.size();
        int len = 0;

        for(int high = 0; high < n; high++){
            f[s[high]]++;
            len = high-low+1;

            while(len > f.size()){
                f[s[low]]--;
                if(f[s[low]] == 0){
                    f.erase(s[low]);
                }
                low++;

                len = high-low+1;
            }

            len = high - low + 1;
            maxLen = max(len, maxLen);
        }

    return maxLen;
    }
};